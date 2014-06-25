/*
 * 这个头文件定义了客户端开发需要使用的接口
 */

#ifndef Plugin_Runtime_H
#define Plugin_Runtime_H

#include "PluginApplicat.h"

/*
 * 获取插件方法
 */
EXTERN_C PLUGINRUNTIME_API struct PluginMethod* GetPluginMethod(struct PluginRuntime* env, const char* name, const char* argv);

/*
 * 调用插件方法
 */
EXTERN_C PLUGINRUNTIME_API void CallPluginMethod(struct PluginRuntime* env, struct PluginMethod* method);

/*
 * 获取方法的变量个数
 */
EXTERN_C PLUGINRUNTIME_API int GetValuesCount(struct PluginMethod* method);

/*
 * 清除方法的变量列表
 */
EXTERN_C PLUGINRUNTIME_API void ClearValues(struct PluginMethod* method);


/*
 * 获取方法的变量的值
 */
EXTERN_C PLUGINRUNTIME_API struct PluginValue* GetValueAt(struct PluginMethod* method, int at);

/*
 * 获取 int 类型的值
 */
EXTERN_C PLUGINRUNTIME_API bool GetIntValue(struct PluginValue* value, int* ret);

/*
 * 获取 bool 类型的值
 */
EXTERN_C PLUGINRUNTIME_API bool GetBoolValue(struct PluginValue* value, bool* ret);

/*
 * 获取 char 类型的值
 */
EXTERN_C PLUGINRUNTIME_API bool GetCharValue(struct PluginValue* value, char* ret);

/*
 * 获取 float 类型的值
 */
EXTERN_C PLUGINRUNTIME_API bool GetFloatValue(struct PluginValue* value, float* ret);

/*
 * 获取 double 类型的值
 */
EXTERN_C PLUGINRUNTIME_API bool GetDoubleValue(struct PluginValue* value, double* ret);

/*
 * 获取 char* 类型的值的长度
 */
EXTERN_C PLUGINRUNTIME_API int GetStringValueLength(struct PluginValue* value);

/*
 * 获取 char* 类型的值
 */
EXTERN_C PLUGINRUNTIME_API bool GetStringValue(struct PluginValue* value, char* str, int len);

/*
 * 获取 void* 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void* GetVoidPtrValue(struct PluginValue* value);


/*
 * 设置 int 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushIntValue(struct PluginMethod* method, int value);

/*
 * 设置 bool 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushBoolValue(struct PluginMethod* method, bool value);

/*
 * 设置 char 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushCharValue(struct PluginMethod* method, char value);

/*
 * 设置 float 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushFloatValue(struct PluginMethod* method, float value);

/*
 * 设置 double 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushDoubleValue(struct PluginMethod* method, double value);

/*
 * 设置 char* 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushStringValue(struct PluginMethod* method, const char* str, int len);

/*
 * 设置 void* 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushVoidPtrValue(struct PluginMethod* method, void* value);

#endif /*Plugin_Runtime_H*/