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
 * 插件使用的变量的值类型
 */
enum PluginValueType
{
	PluginValueType_Null,		// 类型为 空
	PluginValueType_Bool,		// 类型为 bool
	PluginValueType_Byte,		// 类型为 byte
	PluginValueType_Short,		// 类型为 short
	PluginValueType_UShort,		// 类型为 unsigned short
	PluginValueType_Int,		// 类型为 int
	PluginValueType_UInt,		// 类型为 unsigned int
	PluginValueType_Long,		// 类型为 long
	PluginValueType_ULong,		// 类型为 unsigned long
	PluginValueType_LongLong,	// 类型为 long long
	PluginValueType_ULongLong,	// 类型为 unsigned long long
	PluginValueType_Float,		// 类型为 float
	PluginValueType_Double,		// 类型为 double
	PluginValueType_Char,		// 类型为 char
	PluginValueType_String,		// 类型为 char*
	PluginValueType_VoidPtr,	// 类型为 void*
};

/**
 * 插件使用的变量类型
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
	 * 清空变量的值
	 */
	void Clear()
	{
		_valueHolder.reset();
	}

	/**
	 * 获取变量的值类型
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
	 * bool 类型的变量
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
	 * byte 类型的变量
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
	 * short 类型的变量
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
	 * unsigned short 类型的变量
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
	 * int 类型的变量
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
	 * unsigned int 类型的变量
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
	 * long 类型的变量
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
	 * unsigned long 类型的变量
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
	 * long long 类型的变量
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
	 * unsigned long long 类型的变量
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
	 * float 类型的变量
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
	 * double 类型的变量
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
	 * char 类型的变量
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
	 * string 类型的变量
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
	 * void* 类型的变量
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
	 * 通用的值承载器
	 */
	struct PlaceHolder
	{
		PluginValueType _type;
	};

	/**
	 * 具体的值承载器
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
	 * 值承载器
	 */
	shared_ptr<PlaceHolder> _valueHolder;
};

/**
 * 插件的变量值集合
 */
struct PluginValue
{
	// 值集合
	vector<PValue> values;
};

/**
 * 插件的运行时方法
 */
struct PluginMethod
{
	// 方法名称
	string _name;

	// 参数列表
	string _argv;

	// 函数指针
	PluginMethodPtr _method;
};

/**
 * 插件的运行时环境
 */
struct PluginRuntime
{
	// id
	string _id;

	// 方法列表
	map<string, shared_ptr<PluginMethod>> _methods;

	// 对象列表
	map<string, void*> _objects;

	PluginRuntime(string id)
		: _id(id)
	{}
};

#endif /*Plugin_Runtime_Private_H*/