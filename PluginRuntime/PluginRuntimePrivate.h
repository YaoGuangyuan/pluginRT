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
 * ���ʹ�õı�����ֵ����
 */
enum PluginValueType
{
	PluginValueType_Null,	 // ����Ϊ ��
	PluginValueType_Int,	 // ����Ϊ int
	PluginValueType_Bool,	 // ����Ϊ bool
	PluginValueType_Char,	 // ����Ϊ char
	PluginValueType_Float,	 // ����Ϊ float
	PluginValueType_Double,	 // ����Ϊ double
	PluginValueType_String,	 // ����Ϊ char*
	PluginValueType_VoidPtr, // ����Ϊ void*
};

/*
 * ���ʹ�õı�������
 */
struct PluginValue
{
public:
	PluginValue()
		: _valueHolder(NULL) 
	{}

	~PluginValue() 
	{}

	// ��ձ�����ֵ
	void Clear()
	{
		_valueHolder.reset();
	}

	// ��ȡ������ֵ����
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

	// ���� int ���͵ı���
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

	// ���� bool ���͵ı���
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

	// ���� char ���͵ı���
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

	// ���� float ���͵ı���
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

	// ���� double ���͵ı���
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

	// ���� string ���͵ı���
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

	// ���� void* ���͵ı���
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
	ͨ�õ�ֵ������
	*/
	struct PlaceHolder
	{
		PluginValueType _type;
	};

	/*
	�����ֵ������
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
 * ���������ʱ����
 */
struct PluginMethod
{
	// ��������
	string _name;

	// �����б�
	string _argv;

	// ����ָ��
	void* _object;

	// ����ָ��
	PluginMethodPtr _method;

	// ����ֵ�б�
	vector<PluginValue> _values;
};

/*
 * ���������ʱ����
 */
struct PluginRuntime
{
	// id
	string _id;

	// �����б�
	map<string, shared_ptr<PluginMethod>> _methods;

	PluginRuntime(string id)
		: _id(id)
	{}
};

#endif /* Plugin_Runtime_Private_H */