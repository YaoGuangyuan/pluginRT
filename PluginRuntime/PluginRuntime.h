/**
 * 这个头文件供客户端开发使用。
 */

#ifndef Plugin_Runtime_H
#define Plugin_Runtime_H

#include "PluginApplicat.h"

/**
 * 获取插件运行时对象
 * 
 * @Param env
 *        运行时环境
 * @Param yclass
 *        对象的类名
 * @Param name
 *        对象的名称
 * @Return 返回对象句柄
 */
EXTERN_C PLUGINRUNTIME_API void* GetPluginObject(PluginRuntime* env, const char* yclass, const char* name);

/**
 * 获取插件方法
 * 
 * @Param env
 *        运行时环境
 * @Param name
 *        函数名称
 * @Param argv
 *        函数参数列表
 * @Return 返回方法句柄
 */
EXTERN_C PLUGINRUNTIME_API PluginMethod* GetPluginMethod(PluginRuntime* env, const char* name, const char* argv);

/**
 * 调用插件方法
 * 
 * @Param env
 *        运行时环境
 * @Param method
 *        方法句柄
 * @Param obj
 *        对象句柄
 * @Return 返回结果值
 */
EXTERN_C PLUGINRUNTIME_API PluginValue* CallPluginMethod(PluginRuntime* env, PluginMethod* method, void* obj, PluginValue* arg);

/**
 * 获取值句柄
 * 
 * @Return 返回分配好的值句柄
 */
EXTERN_C PLUGINRUNTIME_API PluginValue* MallocValue();

/**
 * 释放值句柄
 *
 * @Param value
 *        值句柄
 */
EXTERN_C PLUGINRUNTIME_API void ReleaseValue(PluginValue* value);

/**
 * 获取变量的个数
 *
 * @Param value
 *        值句柄
 * @Return 返回值的数量
 */
EXTERN_C PLUGINRUNTIME_API uint32_t GetValueCount(PluginValue* value);

/**
 * 获取 bool ('b') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        bool值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetBoolValue(PluginValue* value, uint32_t at, bool* ret);

/**
 * 获取 byte ('B') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        byte值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetByteValue(PluginValue* value, uint32_t at, unsigned char* ret);

/**
 * 获取 short ('h') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        short值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetShortValue(PluginValue* value, uint32_t at, short* ret);

/**
 * 获取 unsigned short ('H') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        unsigned short值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedShortValue(PluginValue* value, uint32_t at, unsigned short* ret);

/**
 * 获取 int ('i') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        int值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetIntValue(PluginValue* value, uint32_t at, int* ret);

/**
 * 获取 unsigned int ('I') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        unsigned int值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedIntValue(PluginValue* value, uint32_t at, unsigned int* ret);

/**
 * 获取 long ('l') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        long值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetLongValue(PluginValue* value, uint32_t at, long* ret);

/**
 * 获取 unsigned long ('k') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        unsigned long值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedLongValue(PluginValue* value, uint32_t at, unsigned long* ret);

/**
 * 获取 long long ('L') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        long long值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetLongLongValue(PluginValue* value, uint32_t at, long long* ret);

/**
 * 获取 unsigned long long ('K') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        unsigned long long值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedLongLongValue(PluginValue* value, uint32_t at, unsigned long long* ret);

/**
 * 获取 float ('f') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        float值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetFloatValue(PluginValue* value, uint32_t at, float* ret);

/**
 * 获取 double ('d') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        double值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetDoubleValue(PluginValue* value, uint32_t at, double* ret);

/**
 * 获取 char ('c') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param ret
 *        char值指针
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetCharValue(PluginValue* value, uint32_t at, char* ret);

/**
 * 获取 char* ('s') 类型的值的长度
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Return 返回字符串的长度
 */
EXTERN_C PLUGINRUNTIME_API uint32_t GetStringValueLength(PluginValue* value, uint32_t at);

/**
 * 获取 char* ('s') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Param str
 *        字符串内存指针
 * @Param len
 *        字符串长度
 * @Return 返回是否成功
 */
EXTERN_C PLUGINRUNTIME_API bool GetStringValue(PluginValue* value, uint32_t at, char* str, uint32_t len);

/**
 * 获取 void* ('p') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param at
 *        值的索引
 * @Return 返回 void* 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void* GetVoidPtrValue(PluginValue* value, uint32_t at);

/**
 * 设置 bool ('b') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        bool 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushBoolValue(PluginValue* value, bool vl);

/**
 * 设置 byte ('B') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        byte 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushByteValue(PluginValue* value, unsigned char vl);

/**
 * 设置 short ('h') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        short 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushShortValue(PluginValue* value, short vl);

/**
 * 设置 unsigned short ('H') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        unsigned short 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedShortValue(PluginValue* value, unsigned short vl);

/**
 * 设置 int ('i') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        int 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushIntValue(PluginValue* value, int vl);

/**
 * 设置 unsigned int ('I') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        unsigned int 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedIntValue(PluginValue* value, unsigned int vl);

/**
 * 设置 long ('l') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        long 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushLongValue(PluginValue* value, long vl);

/**
 * 设置 unsigned long ('k') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        unsigned long 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedLongValue(PluginValue* value, unsigned long vl);

/**
 * 设置 long long ('L') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        long long 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushLongLongValue(PluginValue* value, long long vl);

/**
 * 设置 unsigned long long ('K') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        unsigned long long 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedLongLongValue(PluginValue* value, unsigned long long vl);

/**
 * 设置 float ('f') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        float 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushFloatValue(PluginValue* value, float vl);

/**
 * 设置 double ('d') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        double 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushDoubleValue(PluginValue* value, double vl);

/**
 * 设置 char ('c') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        char 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushCharValue(PluginValue* value, char vl);

/**
 * 设置 char* ('s') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param str
 *        字符串的内存指针
 * @Param len
 *        字符串的长度
 */
EXTERN_C PLUGINRUNTIME_API void PushStringValue(PluginValue* value, const char* str, uint32_t len);

/**
 * 设置 void* ('p') 类型的值
 * 
 * @Param value
 *        变量值的句柄
 * @Param value
 *        void* 类型的值
 */
EXTERN_C PLUGINRUNTIME_API void PushVoidPtrValue(PluginValue* value, void* vl);

#endif /*Plugin_Runtime_H*/