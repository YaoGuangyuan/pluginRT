#include "stdafx.h"
#include "PluginRuntime.h"
#include "PluginRuntimePrivate.h"

/**
 * ��ȡ�������ʱ����
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
 * ��ȡ�������
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
 * ���ò������
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
 * ��ȡֵ���
 */
PluginValue* MallocValue()
{
	return new PluginValue();
}

/**
 * �ͷ�ֵ���
 */
void ReleaseValue(PluginValue* value)
{
	if (value != nullptr)
	{
		delete value;
	}
}

/**
 * ��ȡ�����ĸ���
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
 * ��ȡ bool ('b') ���͵�ֵ
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
 * ��ȡ byte ('B') ���͵�ֵ
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
 * ��ȡ short ('h') ���͵�ֵ
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
 * ��ȡ unsigned short ('H') ���͵�ֵ
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
 * ��ȡ int ('i') ���͵�ֵ
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
 * ��ȡ unsigned int ('I') ���͵�ֵ
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
 * ��ȡ long ('l') ���͵�ֵ
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
 * ��ȡ unsigned long ('k') ���͵�ֵ
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
 * ��ȡ long long ('L') ���͵�ֵ
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
 * ��ȡ unsigned long long ('K') ���͵�ֵ
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
 * ��ȡ float ('f') ���͵�ֵ
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
 * ��ȡ double ('d') ���͵�ֵ
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
 * ��ȡ char ('c') ���͵�ֵ
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
 * ��ȡ char* ('s') ���͵�ֵ�ĳ���
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
 * ��ȡ char* ('s') ���͵�ֵ
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
 * ��ȡ void* ('p') ���͵�ֵ
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
 * ���� bool ('b') ���͵�ֵ
 */
void PushBoolValue(PluginValue* value, bool vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetBoolValue(vl));
	}
}

/**
 * ���� byte ('B') ���͵�ֵ
 */
void PushByteValue(PluginValue* value, unsigned char vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetByteValue(vl));
	}
}

/**
 * ���� short ('h') ���͵�ֵ
 */
void PushShortValue(PluginValue* value, short vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetShortValue(vl));
	}
}

/**
 * ���� unsigned short ('H') ���͵�ֵ
 */
void PushUnsignedShortValue(PluginValue* value, unsigned short vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetUShortValue(vl));
	}
}

/**
 * ���� int ('i') ���͵�ֵ
 */
void PushIntValue(PluginValue* value, int vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetIntValue(vl));
	}
}

/**
 * ���� unsigned int ('I') ���͵�ֵ
 */
void PushUnsignedIntValue(PluginValue* value, unsigned int vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetUIntValue(vl));
	}
}

/**
 * ���� long ('l') ���͵�ֵ
 */
void PushLongValue(PluginValue* value, long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetLongValue(vl));
	}
}

/**
 * ���� unsigned long ('k') ���͵�ֵ
 */
void PushUnsignedLongValue(PluginValue* value, unsigned long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetULongValue(vl));
	}
}

/**
 * ���� long long ('L') ���͵�ֵ
 */
void PushLongLongValue(PluginValue* value, long long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetLongLongValue(vl));
	}
}

/**
 * ���� unsigned long long ('K') ���͵�ֵ
 */
void PushUnsignedLongLongValue(PluginValue* value, unsigned long long vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetULongLongValue(vl));
	}
}

/**
 * ���� float ('f') ���͵�ֵ
 */
void PushFloatValue(PluginValue* value, float vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetFloatValue(vl));
	}
}

/**
 * ���� double ('d') ���͵�ֵ
 */
void PushDoubleValue(PluginValue* value, double vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetDoubleValue(vl));
	}
}

/**
 * ���� char ('c') ���͵�ֵ
 */
void PushCharValue(PluginValue* value, char vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetCharValue(vl));
	}
}

/**
 * ���� char* ('s') ���͵�ֵ
 */
void PushStringValue(PluginValue* value, const char* str, uint32_t len)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetStringValue(string(str, len)));
	}
}

/**
 * ���� void* ('p') ���͵�ֵ
 */
void PushVoidPtrValue(PluginValue* value, void* vl)
{
	if (value != nullptr)
	{
		value->values.push_back(PValue().SetVoidPtrValue(value));
	}
}