/**
 * 这个头文件供服务端开发使用。
 */

#ifndef Plugin_Runtime_0_H
#define Plugin_Runtime_0_H

#include "PluginApplicat.h"

/**
 * 创建一个运行时环境
 * 
 * @Param id
 *        运行时环境的ID
 * @Return 返回运行时环境
 */
EXTERN_C PLUGINRUNTIME_API PluginRuntime* CreatePluginRuntime(const char* id);

/**
 * 删除一个运行时环境
 * 
 * @Param env
 *        运行时环境的（二级）指针
 */
EXTERN_C PLUGINRUNTIME_API void DeletePluginRuntime(PluginRuntime** env);

/**
 * 注册运行时函数的句柄
 */
struct PluginMethodHandle
{
	char*			name;	// 函数名称
	char*			argv;	// 参数列表
	PluginMethodPtr method;	// 函数指针
};

/**
 * 注册运行时函数
 * 
 * @Param env
 *        运行时环境
 * @Param handle
 *        注册函数句柄
 * @Return 返回是否成功注册
 */
EXTERN_C PLUGINRUNTIME_API bool RegisterPluginMethod(PluginRuntime* env, PluginMethodHandle handle);

/**
 * 注册运行时对象的句柄
 */
struct PluginObjectHandle
{
	char* yclass;	// 对象类型
	char* name;		// 对象名称
	void* object;	// 对象指针
};

/**
 * 注册运行时对象
 * 
 * @Param env
 *        运行时环境
 * @Param handle
 *        注册对象句柄
 * @Return 返回是否成功注册
 */
EXTERN_C PLUGINRUNTIME_API bool RegisterPluginObject(PluginRuntime* env, PluginObjectHandle handle);

#endif /*Plugin_Runtime_0_H*/