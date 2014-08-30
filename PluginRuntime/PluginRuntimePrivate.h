#ifndef Plugin_Runtime_Private_H
#define Plugin_Runtime_Private_H

#include "PluginApplicat.h"

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <functional>
using namespace std;

/**
 * ���ʹ�õı�����ֵ����
 */
enum PluginValueType
{
	PluginValueType_Null,		// ����Ϊ ��
	PluginValueType_Bool,		// ����Ϊ bool
	PluginValueType_Byte,		// ����Ϊ byte
	PluginValueType_Short,		// ����Ϊ short
	PluginValueType_UShort,		// ����Ϊ unsigned short
	PluginValueType_Int,		// ����Ϊ int
	PluginValueType_UInt,		// ����Ϊ unsigned int
	PluginValueType_Long,		// ����Ϊ long
	PluginValueType_ULong,		// ����Ϊ unsigned long
	PluginValueType_LongLong,	// ����Ϊ long long
	PluginValueType_ULongLong,	// ����Ϊ unsigned long long
	PluginValueType_Float,		// ����Ϊ float
	PluginValueType_Double,		// ����Ϊ double
	PluginValueType_Char,		// ����Ϊ char
	PluginValueType_String,		// ����Ϊ char*
	PluginValueType_VoidPtr,	// ����Ϊ void*
};

/**
 * ���ʹ�õı�������
 */
struct PValue
{
public:
	PValue()
		: _valueHolder(NULL) 
	{}

	~PValue() 
	{}

	/**
	 * ��ձ�����ֵ
	 */
	void Clear()
	{
		_valueHolder.reset();
	}

	/**
	 * ��ȡ������ֵ����
	 */
	PluginValueType GetValueType()
	{ 
		if (_valueHolder != NULL)
		{
			return _valueHolder->_type;
		}
		else
		{
			return PluginValueType_Null;
		}
	}

	/**
	 * bool ���͵ı���
	 */
	PValue SetBoolValue(bool value)
	{
		_valueHolder.reset(new PluginValueHolder<bool>(value));
		_valueHolder->_type = PluginValueType_Bool;
		return *this;
	}
	bool GetBoolValue(bool& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Bool)
		{
			value = ((PluginValueHolder<bool>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * byte ���͵ı���
	 */
	PValue SetByteValue(unsigned char value)
	{
		_valueHolder.reset(new PluginValueHolder<unsigned char>(value));
		_valueHolder->_type = PluginValueType_Byte;
		return *this;
	}
	bool GetByteValue(unsigned char& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Byte)
		{
			value = ((PluginValueHolder<unsigned char>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * short ���͵ı���
	 */
	PValue SetShortValue(short value)
	{
		_valueHolder.reset(new PluginValueHolder<short>(value));
		_valueHolder->_type = PluginValueType_Short;
		return *this;
	}
	bool GetShortValue(short& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Short)
		{
			value = ((PluginValueHolder<short>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * unsigned short ���͵ı���
	 */
	PValue SetUShortValue(unsigned short value)
	{
		_valueHolder.reset(new PluginValueHolder<unsigned short>(value));
		_valueHolder->_type = PluginValueType_UShort;
		return *this;
	}
	bool GetUShortValue(unsigned short& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_UShort)
		{
			value = ((PluginValueHolder<unsigned short>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * int ���͵ı���
	 */
	PValue SetIntValue(int value)
	{
		_valueHolder.reset(new PluginValueHolder<int>(value));
		_valueHolder->_type = PluginValueType_Int;
		return *this;
	}
	bool GetIntValue(int& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Int)
		{
			value = ((PluginValueHolder<int>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * unsigned int ���͵ı���
	 */
	PValue SetUIntValue(unsigned int value)
	{
		_valueHolder.reset(new PluginValueHolder<unsigned int>(value));
		_valueHolder->_type = PluginValueType_UInt;
		return *this;
	}
	bool GetUIntValue(unsigned int& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_UInt)
		{
			value = ((PluginValueHolder<unsigned int>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * long ���͵ı���
	 */
	PValue SetLongValue(long value)
	{
		_valueHolder.reset(new PluginValueHolder<long>(value));
		_valueHolder->_type = PluginValueType_Long;
		return *this;
	}
	bool GetLongValue(long& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Long)
		{
			value = ((PluginValueHolder<long>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * unsigned long ���͵ı���
	 */
	PValue SetULongValue(unsigned long value)
	{
		_valueHolder.reset(new PluginValueHolder<unsigned long>(value));
		_valueHolder->_type = PluginValueType_ULong;
		return *this;
	}
	bool GetULongValue(unsigned long& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_ULong)
		{
			value = ((PluginValueHolder<unsigned long>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * long long ���͵ı���
	 */
	PValue SetLongLongValue(long long value)
	{
		_valueHolder.reset(new PluginValueHolder<long long>(value));
		_valueHolder->_type = PluginValueType_LongLong;
		return *this;
	}
	bool GetLongLongValue(long long& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_LongLong)
		{
			value = ((PluginValueHolder<long long>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * unsigned long long ���͵ı���
	 */
	PValue SetULongLongValue(unsigned long long value)
	{
		_valueHolder.reset(new PluginValueHolder<unsigned long long>(value));
		_valueHolder->_type = PluginValueType_ULongLong;
		return *this;
	}
	bool GetULongLongValue(unsigned long long& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_ULongLong)
		{
			value = ((PluginValueHolder<unsigned long long>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * float ���͵ı���
	 */
	PValue SetFloatValue(float value)
	{
		_valueHolder.reset(new PluginValueHolder<float>(value));
		_valueHolder->_type = PluginValueType_Float;
		return *this;
	}
	bool GetFloatValue(float& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Float)
		{
			value = ((PluginValueHolder<float>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * double ���͵ı���
	 */
	PValue SetDoubleValue(double value)
	{
		_valueHolder.reset(new PluginValueHolder<double>(value));
		_valueHolder->_type = PluginValueType_Double;
		return *this;
	}
	bool GetDoubleValue(double& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Double)
		{
			value = ((PluginValueHolder<double>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * char ���͵ı���
	 */
	PValue SetCharValue(char value)
	{
		_valueHolder.reset(new PluginValueHolder<char>(value));
		_valueHolder->_type = PluginValueType_Char;
		return *this;
	}
	bool GetCharValue(char& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_Char)
		{
			value = ((PluginValueHolder<char>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * string ���͵ı���
	 */
	PValue SetStringValue(string value)
	{
		_valueHolder.reset(new PluginValueHolder<string>(value));
		_valueHolder->_type = PluginValueType_String;
		return *this;
	}
	bool GetStringValue(string& value)
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_String)
		{
			value = ((PluginValueHolder<string>*)_valueHolder.get())->_value;
			return true;
		}
		else
		{
			return false;
		}
	}

	/**
	 * void* ���͵ı���
	 */
	PValue SetVoidPtrValue(void* value)
	{
		_valueHolder.reset(new PluginValueHolder<void*>(value));
		_valueHolder->_type = PluginValueType_VoidPtr;
		return *this;
	}
	void* GetVoidPtrValue()
	{
		if (_valueHolder != NULL && _valueHolder->_type == PluginValueType_VoidPtr)
		{
			return ((PluginValueHolder<void*>*)_valueHolder.get())->_value;
		}
		else
		{
			return NULL;
		}
	}

private:

	/**
	 * ͨ�õ�ֵ������
	 */
	struct PlaceHolder
	{
		PluginValueType _type;
	};

	/**
	 * �����ֵ������
	 */
	template<typename T>
	struct PluginValueHolder : public PlaceHolder
	{
		PluginValueHolder(T v)
			: _value(v) 
		{}

		T _value;
	};

	/**
	 * ֵ������
	 */
	shared_ptr<PlaceHolder> _valueHolder;
};

/**
 * ����ı���ֵ����
 */
struct PluginValue
{
	// ֵ����
	vector<PValue> values;
};

/**
 * ���������ʱ����
 */
struct PluginMethod
{
	// ��������
	string _name;

	// �����б�
	string _argv;

	// ����ָ��
	PluginMethodPtr _method;
};

/**
 * ���������ʱ����
 */
struct PluginRuntime
{
	// id
	string _id;

	// �����б�
	map<string, shared_ptr<PluginMethod>> _methods;

	// �����б�
	map<string, void*> _objects;

	PluginRuntime(string id)
		: _id(id)
	{}
};

#endif /*Plugin_Runtime_Private_H*/