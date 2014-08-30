#include "stdafx.h"
#include "PluginRuntime0.h"
#include "PluginRuntimePrivate.h"

/**
 * ȫ�ֵ�����ʱ�����б�
 */
static map<string, PluginRuntime*> gPluginRuntimes;

/**
 * ����ָ������ʱ����
 * 
 * @Param id
 *        ����ʱ������ID
 * @Return ��������ʱ����
 */
static PluginRuntime* FindPluginRuntime(string id)
{
	auto iter = gPluginRuntimes.find(id);
	if (iter != gPluginRuntimes.end())
	{
		return (*iter).second;
	}
	return NULL;
}

/**
 * ����һ������ʱ����
 */
PluginRuntime* CreatePluginRuntime(const char* id)
{
	PluginRuntime* env = FindPluginRuntime(id);
	if (env != NULL)
	{
		return env;
	}

	env = new PluginRuntime(id);

	auto ret = gPluginRuntimes.insert(make_pair(id, env));
	if (!ret.second)
	{
		delete env;
		return NULL;
	}

	return env;
}

/**
 * ɾ��һ������ʱ����
 */
void DeletePluginRuntime(PluginRuntime** env)
{
	if (env != NULL && *env != NULL)
	{
		auto iter = gPluginRuntimes.find((*env)->_id);
		if (iter != gPluginRuntimes.end())
		{
			gPluginRuntimes.erase(iter);
			
			delete (*env);
			(*env) = NULL;
		}
	}
}

/**
 * ע������ʱ����
 */
bool RegisterPluginMethod(PluginRuntime* env, PluginMethodHandle handle)
{
	if (env != NULL)
	{
		string method_id = string(handle.name) + "@" + string(handle.argv);
		auto iter = env->_methods.find(method_id);
		if (iter != env->_methods.end())
		{
			return false;
		}

		shared_ptr<PluginMethod> method(new PluginMethod());
		method->_name = handle.name;
		method->_argv = handle.argv;
		method->_method = handle.method;

		auto ret = env->_methods.insert(make_pair(method_id, method));
		return ret.second;
	}

	return false;
}

/**
 * ע������ʱ����
 */
bool RegisterPluginObject(PluginRuntime* env, PluginObjectHandle handle)
{
	if (env != NULL)
	{
		string object_id = string(handle.yclass) + "::" + string(handle.name);
		auto iter = env->_objects.find(object_id);
		if (iter != env->_objects.end())
		{
			return false;
		}

		auto ret = env->_objects.insert(make_pair(object_id, handle.object));
		return ret.second;
	}

	return false;
}