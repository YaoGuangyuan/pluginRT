#include "stdafx.h"
#include <Windows.h>

#include "../PluginRuntime/PluginRuntime.h"
#include "../PluginRuntime/PluginRuntime0.h"

#include <string>
using namespace std;

PluginValue* Add(PluginMethod* method, void* object, PluginValue* arg)
{
	int m1;
	GetIntValue(arg, 0, &m1);

	int m2;
	GetIntValue(arg, 1, &m2);

	PluginValue* ret = MallocValue();
	PushIntValue(ret, m1 + m2);
	return ret;
}

PluginValue* Cat(PluginMethod* method, void* object, PluginValue* arg)
{
	int len1 = GetStringValueLength(arg, 0);
	char* str1 = new char[len1 + 1];
	GetStringValue(arg, 0, str1, len1 + 1);

	int len2 = GetStringValueLength(arg, 1);
	char* str2 = new char[len2 + 1];
	GetStringValue(arg, 1, str2, len2 + 1);

	string s1(str1, len1);
	string s2(str2, len2);
	string s = s1 + s2;

	delete str1;
	delete str2;

	PluginValue* ret = MallocValue();
	PushStringValue(ret, s.c_str(), s.length());
	return ret;
}

PluginValue* Vet(PluginMethod* method, void* object, PluginValue* arg)
{
	bool m;
	GetBoolValue(arg, 0, &m);

	PluginValue* ret = MallocValue();
	PushBoolValue(ret, !m);
	return ret;
}

int _tmain(int argc, _TCHAR* argv[])
{
	PluginRuntime* env = CreatePluginRuntime("demo");

	PluginMethodHandle add;
	add.name = "Add";
	add.argv = "(ii)i";
	add.method = Add;
	RegisterPluginMethod(env, add);

	PluginMethodHandle cat;
	cat.name = "Cat";
	cat.argv = "(ss)s";
	cat.method = Cat;
	RegisterPluginMethod(env, cat);

	PluginMethodHandle vet;
	vet.name = "Vet";
	vet.argv = "(b)b";
	vet.method = Vet;
	RegisterPluginMethod(env, vet);

	/*
	 * 加载运行插件
	 */
	{
		typedef void (*OnPluginLoad)(PluginRuntime* env);
		
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

