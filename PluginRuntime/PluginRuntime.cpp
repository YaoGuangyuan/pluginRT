#include "stdafx.h"
#include "PluginRuntime.h"
#include "PluginRuntimePrivate.h"

/*
 * 获取插件方法
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
 * 调用插件方法
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
 * 获取方法的变量个数
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
 * 清除方法的变量列表
 */
void ClearValues(struct PluginMethod* method)
{
	if (method != NULL)
	{
		method->_values.clear();
	}
}

/*
 * 获取方法的变量的值
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
 * 获取 int 类型的值
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
 * 获取 bool 类型的值
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
 * 获取 char 类型的值
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
 * 获取 float 类型的值
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
 * 获取 double 类型的值
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
 * 获取 char* 类型的值的长度
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
 * 获取 char* 类型的值
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
 * 获取 void* 类型的值
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
 * 设置 int 类型的值
 */
void PushIntValue(struct PluginMethod* method, int value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetIntValue(value));
	}
}

/*
 * 设置 bool 类型的值
 */
void PushBoolValue(struct PluginMethod* method, bool value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetBoolValue(value));
	}
}

/*
 * 设置 char 类型的值
 */
void PushCharValue(struct PluginMethod* method, char value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetCharValue(value));
	}
}

/*
 * 设置 float 类型的值
 */
void PushFloatValue(struct PluginMethod* method, float value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetFloatValue(value));
	}
}

/*
 * 设置 double 类型的值
 */
void PushDoubleValue(struct PluginMethod* method, double value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetDoubleValue(value));
	}
}

/*
 * 设置 char* 类型的值
 */
void PushStringValue(struct PluginMethod* method, const char* str, int len)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetStringValue(string(str, len)));
	}
}

/*
 * 设置 void* 类型的值
 */
void PushVoidPtrValue(struct PluginMethod* method, void* value)
{
	if (method != NULL)
	{
		method->_values.push_back(PluginValue().SetVoidPtrValue(value));
	}
}