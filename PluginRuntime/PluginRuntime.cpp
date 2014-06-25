#include "stdafx.h"
#include "PluginRuntime.h"
#include "PluginRuntimePrivate.h"

/*
 * ��ȡ�������
 */
struct PluginMethod* GetPluginMethod(struct PluginRuntime* env, const char* name, const char* argv)
{
	if (env != NULL)
	{
		string method_id = string(name) + "@" + string(argv);
		auto iter = env->_methods.find(method_id);
		if (iter != env->_methods.end())
		{
			return (*iter).second.get();
		}
	}
	return NULL;
}

/*
 * ���ò������
 */
void CallPluginMethod(struct PluginRuntime* env, struct PluginMethod* method)
{
	if (env != NULL && method != NULL)
	{
		string method_id = method->_name + "@" + method->_argv;
		auto iter = env->_methods.find(method_id);
		if (iter != env->_methods.end())
		{
			method->_method(method, method->_object);
		}
	}
}

/*
 * ��ȡ�����ı�������
 */
int GetValuesCount(struct PluginMethod* method)
{
	if (method != NULL)
	{
		return method->_values.size();
	}
	return -1;
}

/*
 * ��������ı����б�
 */
void ClearValues(struct PluginMethod* method)
{
	if (method != NULL)
	{
		method->_values.clear();
	}
}

/*
 * ��ȡ�����ı�����ֵ
 */
struct PluginValue* GetValueAt(struct PluginMethod* method, int at)
{
	if (method != NULL && at < GetValuesCount(method))
	{
		return &method->_values.at(at);
	}
	return NULL;
}

/*
 * ��ȡ int ���͵�ֵ
 */
bool GetIntValue(struct PluginValue* value, int* ret)
{
	if (value != NULL)
	{
		return value->GetIntValue(*ret);
	}
	return false;
}

/*
 * ��ȡ bool ���͵�ֵ
 */
bool GetBoolValue(struct PluginValue* value, bool* ret)
{
	if (value != NULL)
	{
		return value->GetBoolValue(*ret);
	}
	return false;
}

/*
 * ��ȡ char ���͵�ֵ
 */
bool GetCharValue(struct PluginValue* value, char* ret)
{
	if (value != NULL)
	{
		return value->GetCharValue(*ret);
	}
	return false;
}

/*
 * ��ȡ float ���͵�ֵ
 */
bool GetFloatValue(struct PluginValue* value, float* ret)
{
	if (value != NULL)
	{
		return value->GetFloatValue(*ret);
	}
	return false;
}

/*
 * ��ȡ double ���͵�ֵ
 */
bool GetDoubleValue(struct PluginValue* value, double* ret)
{
	if (value != NULL)
	{
		return value->GetDoubleValue(*ret);
	}
	return false;
}

/*
 * ��ȡ char* ���͵�ֵ�ĳ���
 */
int GetStringValueLength(struct PluginValue* value)
{
	if (value != NULL)
	{
		string ret;
		value->GetStringValue(ret);
		return ret.length();
	}
	return -1;
}

/*
 * ��ȡ char* ���͵�ֵ
 */
bool GetStringValue(struct PluginValue* value, char* str, int len)
{
	if (value != NULL)
	{
		string ret;
		value->GetStringValue(ret);
		strcpy_s(str, len, ret.c_str());
		return true;
	}
	return false;
}

/*
 * ��ȡ void* ���͵�ֵ
 */
void* GetVoidPtrValue(struct PluginValue* value)
{
	if (value != NULL)
	{
		return value->GetVoidPtrValue();
	}
	return NULL;
}

/*
 * ���� int ���͵�ֵ
 */
void PushIntValue(struct PluginMethod* method, int value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetIntValue(value));
	}
}

/*
 * ���� bool ���͵�ֵ
 */
void PushBoolValue(struct PluginMethod* method, bool value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetBoolValue(value));
	}
}

/*
 * ���� char ���͵�ֵ
 */
void PushCharValue(struct PluginMethod* method, char value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetCharValue(value));
	}
}

/*
 * ���� float ���͵�ֵ
 */
void PushFloatValue(struct PluginMethod* method, float value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetFloatValue(value));
	}
}

/*
 * ���� double ���͵�ֵ
 */
void PushDoubleValue(struct PluginMethod* method, double value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetDoubleValue(value));
	}
}

/*
 * ���� char* ���͵�ֵ
 */
void PushStringValue(struct PluginMethod* method, const char* str, int len)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetStringValue(string(str, len)));
	}
}

/*
 * ���� void* ���͵�ֵ
 */
void PushVoidPtrValue(struct PluginMethod* method, void* value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetVoidPtrValue(value));
	}
}