#ifndef Plugin_Runtime_0_H
#define Plugin_Runtime_0_H

#include "PluginApplicat.h"

/*
 * 创建一个运行时环境
 */
EXTERN_C PLUGINRUNTIME_API struct PluginRuntime* CreatePluginRuntime(const char* id);

/*
 * 删除一个运行时环境
 */
EXTERN_C PLUGINRUNTIME_API void DeletePluginRuntime(struct PluginRuntime** env);

/*
 * 注册运行时函数的句柄
 */
struct PluginMethodHandle
{
	char*			name;	// 函数名称
	char*			argv;	// 参数列表
	PluginMethodPtr method;	// 函数指针
	void*			object;	// 对象指针
};

/*
 * 注册运行时函数
 */
EXTERN_C PLUGINRUNTIME_API bool RegisterPluginMethod(struct PluginRuntime* env, struct PluginMethodHandle handle);

#endif /*Plugin_Runtime_0_H*/