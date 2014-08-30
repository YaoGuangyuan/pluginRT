#include "stdafx.h"
#include "PluginRuntime.h"
#include "PluginRuntimePrivate.h"

/**
 * 获取插件运行时对象
 */
void* GetPluginObject(PluginRuntime* env, const char* yclass, const char* name)
{
	if (env != nullptr)
	{
		string object_id = string(yclass) + "::" + string(name);
		auto iter = env->_objects.find(object_id);
		if (iter != env->_objects.end())
		{
			return (*iter).second;
		}
	}
	return nullptr;
}

/**
 * 获取插件方法
 */
PluginMethod* GetPluginMethod(PluginRuntime* env, const char* name, const char* argv)
{
	if (env != nullptr)
	{
		string method_id = string(name) + "@" + string(argv);
		auto iter = env->_methods.find(method_id);
		if (iter != env->_methods.end())
		{
			return (*iter).second.get();
		}
	}
	return nullptr;
}

/**
 * 调用插件方法
 */
PluginValue* CallPluginMethod(PluginRuntime* env, PluginMethod* method, void* obj, PluginValue* arg)
{
	if (env != nullptr && method != nullptr)
	{
		return method->_method(method, obj, arg);
	}
	return nullptr;
}

/**
 * 获取值句柄
 */
PluginValue* MallocValue()
{
	return new PluginValue();
}

/**
 * 释放值句柄
 */
void ReleaseValue(PluginValue* value)
{
	if (value != nullptr)
	{
		delete value;
	}
}

/**
 * 获取变量的个数
 */
uint32_t GetValueCount(PluginValue* value)
{
	if (value != nullptr)
	{
		return value->values.size();
	}
	return 0;
}

/**
 * 获取 bool ('b') 类型的值
 */
bool GetBoolValue(PluginValue* value, uint32_t at, bool* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetBoolValue(*ret);
	}
	return false;
}

/**
 * 获取 byte ('B') 类型的值
 */
bool GetByteValue(PluginValue* value, uint32_t at, unsigned char* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetByteValue(*ret);
	}
	return false;
}

/**
 * 获取 short ('h') 类型的值
 */
bool GetShortValue(PluginValue* value, uint32_t at, short* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetShortValue(*ret);
	}
	return false;
}

/**
 * 获取 unsigned short ('H') 类型的值
 */
bool GetUnsignedShortValue(PluginValue* value, uint32_t at, unsigned short* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetUShortValue(*ret);
	}
	return false;
}

/**
 * 获取 int ('i') 类型的值
 */
bool GetIntValue(PluginValue* value, uint32_t at, int* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetIntValue(*ret);
	}
	return false;
}

/**
 * 获取 unsigned int ('I') 类型的值
 */
bool GetUnsignedIntValue(PluginValue* value, uint32_t at, unsigned int* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetUIntValue(*ret);
	}
	return false;
}

/**
 * 获取 long ('l') 类型的值
 */
bool GetLongValue(PluginValue* value, uint32_t at, long* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetLongValue(*ret);
	}
	return false;
}

/**
 * 获取 unsigned long ('k') 类型的值
 */
bool GetUnsignedLongValue(PluginValue* value, uint32_t at, unsigned long* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetULongValue(*ret);
	}
	return false;
}

/**
 * 获取 long long ('L') 类型的值
 */
bool GetLongLongValue(PluginValue* value, uint32_t at, long long* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetLongLongValue(*ret);
	}
	return false;
}

/**
 * 获取 unsigned long long ('K') 类型的值
 */
bool GetUnsignedLongLongValue(PluginValue* value, uint32_t at, unsigned long long* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetULongLongValue(*ret);
	}
	return false;
}

/**
 * 获取 float ('f') 类型的值
 */
bool GetFloatValue(PluginValue* value, uint32_t at, float* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetFloatValue(*ret);
	}
	return false;
}

/**
 * 获取 double ('d') 类型的值
 */
bool GetDoubleValue(PluginValue* value, uint32_t at, double* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetDoubleValue(*ret);
	}
	return false;
}

/**
 * 获取 char ('c') 类型的值
 */
bool GetCharValue(PluginValue* value, uint32_t at, char* ret)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetCharValue(*ret);
	}
	return false;
}

/**
 * 获取 char* ('s') 类型的值的长度
 */
uint32_t GetStringValueLength(PluginValue* value, uint32_t at)
{
	if (value != nullptr && at < value->values.size())
	{
		string ret;
		value->values.at(at).GetStringValue(ret);
		return ret.length();
	}
	return 0;
}

/**
 * 获取 char* ('s') 类型的值
 */
bool GetStringValue(PluginValue* value, uint32_t at, char* str, uint32_t len)
{
	if (value != nullptr && at < value->values.size())
	{
		string ret;
		value->values.at(at).GetStringValue(ret);
		strcpy_s(str, len, ret.c_str());
		return true;
	}
	return false;
}

/**
 * 获取 void* ('p') 类型的值
 */
void* GetVoidPtrValue(PluginValue* value, uint32_t at)
{
	if (value != nullptr && at < value->values.size())
	{
		return value->values.at(at).GetVoidPtrValue();
	}
	return nullptr;
}

/**
 * 设置 bool ('b') 类型的值
 */
void PushBoolValue(PluginValue* value, bool vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetBoolValue(vl));
	}
}

/**
 * 设置 byte ('B') 类型的值
 */
void PushByteValue(PluginValue* value, unsigned char vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetByteValue(vl));
	}
}

/**
 * 设置 short ('h') 类型的值
 */
void PushShortValue(PluginValue* value, short vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetShortValue(vl));
	}
}

/**
 * 设置 unsigned short ('H') 类型的值
 */
void PushUnsignedShortValue(PluginValue* value, unsigned short vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetUShortValue(vl));
	}
}

/**
 * 设置 int ('i') 类型的值
 */
void PushIntValue(PluginValue* value, int vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetIntValue(vl));
	}
}

/**
 * 设置 unsigned int ('I') 类型的值
 */
void PushUnsignedIntValue(PluginValue* value, unsigned int vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetUIntValue(vl));
	}
}

/**
 * 设置 long ('l') 类型的值
 */
void PushLongValue(PluginValue* value, long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetLongValue(vl));
	}
}

/**
 * 设置 unsigned long ('k') 类型的值
 */
void PushUnsignedLongValue(PluginValue* value, unsigned long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetULongValue(vl));
	}
}

/**
 * 设置 long long ('L') 类型的值
 */
void PushLongLongValue(PluginValue* value, long long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetLongLongValue(vl));
	}
}

/**
 * 设置 unsigned long long ('K') 类型的值
 */
void PushUnsignedLongLongValue(PluginValue* value, unsigned long long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetULongLongValue(vl));
	}
}

/**
 * 设置 float ('f') 类型的值
 */
void PushFloatValue(PluginValue* value, float vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetFloatValue(vl));
	}
}

/**
 * 设置 double ('d') 类型的值
 */
void PushDoubleValue(PluginValue* value, double vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetDoubleValue(vl));
	}
}

/**
 * 设置 char ('c') 类型的值
 */
void PushCharValue(PluginValue* value, char vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetCharValue(vl));
	}
}

/**
 * 设置 char* ('s') 类型的值
 */
void PushStringValue(PluginValue* value, const char* str, uint32_t len)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetStringValue(string(str, len)));
	}
}

/**
 * 设置 void* ('p') 类型的值
 */
void PushVoidPtrValue(PluginValue* value, void* vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetVoidPtrValue(value));
	}
}