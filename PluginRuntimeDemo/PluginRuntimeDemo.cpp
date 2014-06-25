#include "stdafx.h"
#include <Windows.h>

#include "../PluginRuntime/PluginRuntime.h"
#include "../PluginRuntime/PluginRuntime0.h"

#include <string>
using namespace std;

void Add(struct PluginMethod* method, void* object)
{
	int m1;
	GetIntValue(GetValueAt(method, 0), &m1);

	int m2;
	GetIntValue(GetValueAt(method, 1), &m2);

	ClearValues(method);

	PushIntValue(method, m1 + m2);
}

void Cat(struct PluginMethod* method, void* object)
{
	struct PluginValue* value = GetValueAt(method, 0);
	int len1 = GetStringValueLength(value);
	char* str1 = new char[len1 + 1];
	GetStringValue(value, str1, len1 + 1);

	value = GetValueAt(method, 1);
	int len2 = GetStringValueLength(value);
	char* str2 = new char[len2 + 1];
	GetStringValue(value, str2, len2 + 1);

	string s1(str1, len1);
	string s2(str2, len2);
	string s = s1 + s2;

	ClearValues(method);

	PushStringValue(method, s.c_str(), s.length());
}

void Vet(struct PluginMethod* method, void* object)
{
	bool m;
	GetBoolValue(GetValueAt(method, 0), &m);

	ClearValues(method);

	PushBoolValue(method, !m);
}

int _tmain(int argc, _TCHAR* argv[])
{
	struct PluginRuntime* env = CreatePluginRuntime("demo");

	PluginMethodHandle add;
	add.name = "Add";
	add.argv = "(ii)i";
	add.object = NULL;
	add.method = Add;
	RegisterPluginMethod(env, add);

	PluginMethodHandle cat;
	cat.name = "Cat";
	cat.argv = "(^s^s)^s";
	cat.object = NULL;
	cat.method = Cat;
	RegisterPluginMethod(env, cat);

	PluginMethodHandle vet;
	vet.name = "Vet";
	vet.argv = "(b)b";
	vet.object = NULL;
	vet.method = Vet;
	RegisterPluginMethod(env, vet);

	/*
	 * 加载运行插件
	 */
	{
		typedef void (*OnPluginLoad)(struct PluginRuntime* env);
		
		HMODULE pluginDll = LoadLibraryA("PluginExample.dll");

		OnPluginLoad pluginLoadEntry = NULL;
		pluginLoadEntry = (OnPluginLoad)GetProcAddress(pluginDll, "OnPluginLoad");
		if (pluginLoadEntry != NULL)
		{
			pluginLoadEntry(env);
		}

		typedef void (*Call)();
		Call call = NULL;
		call = (Call)GetProcAddress(pluginDll, "Call");
		if (call != NULL)
		{
			call();
		}

		FreeLibrary(pluginDll);
	}

	DeletePluginRuntime(&env);

	return 0;
}

