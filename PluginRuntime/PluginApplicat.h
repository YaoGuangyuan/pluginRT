/*
 * 这个文件是公共头文件，必须被包含。
 */

#ifndef Plugin_Applicat_H
#define Plugin_Applicat_H

#ifndef PLUGINRUNTIME_API
#	ifdef PLUGINRUNTIME_EXPORTS
#		define PLUGINRUNTIME_API __declspec(dllexport)
#	else
#		define PLUGINRUNTIME_API __declspec(dllimport)
#	endif
#endif

#ifndef EXTERN_C
#	define EXTERN_C extern "C"
#endif

/*
 * 插件的变量值类型
 */
struct PluginValue;

/*
 * 插件的运行时方法
 */
struct PluginMethod;

/*
 * 插件的运行时环境
 */
struct PluginRuntime;

/*
 * 定义可以接受的注册函数
 */
typedef void(*PluginMethodPtr)(struct PluginMethod* method, void* object);

#endif /*Plugin_Applicat_H*/