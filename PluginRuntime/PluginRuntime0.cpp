#include "stdafx.h"
#include "PluginRuntime0.h"
#include "PluginRuntimePrivate.h"

#include <map>
using namespace std;

/*
 * ȫ�ֵ�����ʱ�����б�
 */
map<string, struct PluginRuntime*> gPluginRuntimes;

/*
 * ����ָ������ʱ����
 */
static struct PluginRuntime* FindPluginRuntime(string id)
{
	auto iter = gPluginRuntimes.find(id);
	if (iter != gPluginRuntimes.end())
	{
		return (*iter).second;
	}
	return NULL;
}

/*
 * ����һ������ʱ����
 */
struct PluginRuntime* CreatePluginRuntime(const char* id)
{
	struct PluginRuntime* env;

	env = FindPluginRuntime(id);
	if (env != NULL)
	{
		return env;
	}

	env = new struct PluginRuntime(id);
	auto ret = gPluginRuntimes.insert(make_pair(id, env));
	if (!ret.second)
	{
		delete env;
		return NULL;
	}

	return env;
}

/*
 * ɾ��һ������ʱ����
 */
void DeletePluginRuntime(struct PluginRuntime** env)
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

/*
 * ע������ʱ����
 */
bool RegisterPluginMethod(struct PluginRuntime* env, struct PluginMethodHandle handle)
{
	if (env != NULL)
	{
		string method_id = string(handle.name) + "@" + string(handle.argv);
		auto iter = env->_methods.find(method_id);
		if (iter != env->_methods.end())
		{
			return false;
		}

		struct PluginMethod* method = new struct PluginMethod();
		method->_name = handle.name;
		method->_argv = handle.argv;
		method->_object = handle.object;
		method->_method = handle.method;

		auto ret = env->_methods.insert(make_pair(method_id, method));
		if (!ret.second)
		{
			delete method;
		}
		return ret.second;
	}

	return false;
}