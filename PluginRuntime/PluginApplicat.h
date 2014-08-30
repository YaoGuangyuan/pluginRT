/**
 * 这个文件是公共头文件，必须被包含。
 */

#ifndef Plugin_Applicat_H
#define Plugin_Applicat_H

#ifndef PLUGINRUNTIME_API
#	ifdef PLUGINRUNTIME_EXPORTS
#		define PLUGINRUNTIME_API __declspec(dllexport)
#	else
#		define PLUGINRUNTIME_API
#	endif
#endif

#ifndef EXTERN_C
#	define EXTERN_C extern "C"
#endif

#include <stdint.h>

/**
 * 插件的变量值集合
 */
struct PluginValue;

/**
 * 插件的运行时方法
 */
struct PluginMethod;

/**
 * 插件的运行时环境
 */
struct PluginRuntime;

/**
 * 定义函数原型
 * 
 * @Param method
 *        运行时方法
 * @Param object
 *        自定义客户端对象
 * @Param arg
 *        运行时方法的参数
 * @Return 返回值的句柄
 */
typedef PluginValue* (*PluginMethodPtr) (PluginMethod* method, void* object, PluginValue* arg);

/********************************************************************/
/*                       基本的数据类型                             */
/*																	*/
/*  类型简写	基本类型				不定参数类型				*/
/*  b			bool					int							*/
/*  B			byte					int							*/
/*  h			short					int							*/
/*  H			unsigned short			unsigned int				*/
/*  i			int						int							*/
/*  I			unsigned int			unsigned int				*/
/*  l			long					long						*/
/*  k			unsigned long			unsigned long				*/
/*  L			long long				long long					*/
/*  K			unsigned long long		unsigned long long			*/
/*  f			float					double						*/
/*  d			double					double						*/
/*  c			char					int							*/
/*  s			char*					char*						*/
/*  p			void*					void*						*/
/*  v			void					void
/********************************************************************/

#endif /*Plugin_Applicat_H*/