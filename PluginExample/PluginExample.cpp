#include "stdafx.h"
#include "PluginExample.h"

/*
 * ����ʱ��������
 */
static PluginRuntime* g_env;

/*
 * ��JNI�����
 */
void OnPluginLoad(PluginRuntime* env)
{
	g_env = env;
}

/*
 * ������ù���
 */
void Call()
{
	// Add
	{
		PluginMethod* Add = GetPluginMethod(g_env, "Add", "(ii)i");

		PluginValue* value = MallocValue();
		PushIntValue(value, 3);
		PushIntValue(value, 4);

		PluginValue* ret = CallPluginMethod(g_env, Add, NULL, value);

		int m1;
		GetIntValue(ret, 0, &m1);

		ReleaseValue(ret);
		ReleaseValue(value);
	}
	
	// Cat
	{
		PluginMethod* Cat = GetPluginMethod(g_env, "Cat", "(ss)s");

		PluginValue* value = MallocValue();
		PushStringValue(value, "abc", strlen("abc"));
		PushStringValue(value, "def", strlen("def"));

		PluginValue* ret = CallPluginMethod(g_env, Cat, NULL, value);

		int len1 = GetStringValueLength(ret, 0);
		char* str1 = new char[len1 + 1];
		GetStringValue(ret, 0, str1, len1 + 1);

		ReleaseValue(ret);
		ReleaseValue(value);

		delete str1;
	}
	
	// Vet
	{
		PluginMethod* Vet = GetPluginMethod(g_env, "Vet", "(b)b");

		PluginValue* value = MallocValue();
		PushBoolValue(value, true);

		PluginValue* ret = CallPluginMethod(g_env, Vet, NULL, value);

		bool b;
		GetBoolValue(ret, 0, &b);

		ReleaseValue(ret);
		ReleaseValue(value);
	}
}