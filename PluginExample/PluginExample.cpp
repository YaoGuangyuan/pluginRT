#include "stdafx.h"
#include "PluginExample.h"

/*
 * 运行时环境变量
 */
static struct PluginRuntime* g_env;

/*
 * 和JNI很像吧
 */
void OnPluginLoad(struct PluginRuntime* env)
{
	g_env = env;
}

/*
 * 反向调用过程
 */
void Call()
{
	struct PluginMethod* Add = GetPluginMethod(g_env, "Add", "(ii)i");
	ClearValues(Add);
	PushIntValue(Add, 3);
	PushIntValue(Add, 4);
	CallPluginMethod(g_env, Add);
	
	int m1;
	GetIntValue(GetValueAt(Add, 0), &m1);

	struct PluginMethod* Cat = GetPluginMethod(g_env, "Cat", "(^s^s)^s");
	ClearValues(Cat);
	PushStringValue(Cat, "abc", strlen("abc"));
	PushStringValue(Cat, "def", strlen("def"));
	CallPluginMethod(g_env, Cat);

	struct PluginValue* value = GetValueAt(Cat, 0);
	int len1 = GetStringValueLength(value);
	char* str1 = new char[len1 + 1];
	GetStringValue(value, str1, len1 + 1);

	struct PluginMethod* Vet = GetPluginMethod(g_env, "Vet", "(b)b");
	ClearValues(Vet);
	PushBoolValue(Vet, true);
	CallPluginMethod(g_env, Vet);

	bool b;
	GetBoolValue(GetValueAt(Vet, 0), &b);
}