#ifndef Plugin_Runtime_Private_H
#define Plugin_Runtime_Private_H

#include "PluginApplicat.h"

#include <map>
#include <string>
#include <memory>
#include <vector>
#include <functional>
using namespace std;

/*
 * 插件使用的变量的值类型
 */
enum PluginValueType
{
	PluginValueType_Null,	 // 类型为 空
	PluginValueType_Int,	 // 类型为 int
	PluginValueType_Bool,	 // 类型为 bool
	PluginValueType_Char,	 // 类型为 char
	PluginValueType_Float,	 // 类型为 float
	PluginValueType_Double,	 // 类型为 double
	PluginValueType_String,	 // 类型为 char*
	PluginValueType_VoidPtr, // 类型为 void*
};

/*
 * 插件使用的变量类型
 */
struct PluginValue
{
public:
	PluginValue()
		: _valueHolder(NULL) 
	{}

	~PluginValue() 
	{}

	// 清空变量的值
	void Clear()
	{
		_valueHolder.reset();
	}

	// 获取变量的值类型
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

	// 设置 int 类型的变量
	PluginValue SetIntValue(int value)
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

	// 设置 bool 类型的变量
	PluginValue SetBoolValue(bool value)
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

	// 设置 char 类型的变量
	PluginValue SetCharValue(char value)
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

	// 设置 float 类型的变量
	PluginValue SetFloatValue(float value)
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

	// 设置 double 类型的变量
	PluginValue SetDoubleValue(double value)
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

	// 设置 string 类型的变量
	PluginValue SetStringValue(string value)
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

	// 设置 void* 类型的变量
	PluginValue SetVoidPtrValue(void* value)
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

	/*
	通用的值承载器
	*/
	struct PlaceHolder
	{
		PluginValueType _type;
	};

	/*
	具体的值承载器
	*/
	template<typename T>
	struct PluginValueHolder : public PlaceHolder
	{
		PluginValueHolder(T v)
			: _value(v) 
		{}

		T _value;
	};

	shared_ptr<PlaceHolder> _valueHolder;
};

/*
 * 插件的运行时方法
 */
struct PluginMethod
{
	// 方法名称
	string _name;

	// 参数列表
	string _argv;

	// 对象指针
	void* _object;

	// 函数指针
	PluginMethodPtr _method;

	// 参数值列表
	vector<PluginValue> _values;
};

/*
 * 插件的运行时环境
 */
struct PluginRuntime
{
	// id
	string _id;

	// 方法列表
	map<string, shared_ptr<PluginMethod>> _methods;

	PluginRuntime(string id)
		: _id(id)
	{}
};

#endif /* Plugin_Runtime_Private_H */