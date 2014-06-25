/*
 * ���ͷ�ļ������˿ͻ��˿�����Ҫʹ�õĽӿ�
 */

#ifndef Plugin_Runtime_H
#define Plugin_Runtime_H

#include "PluginApplicat.h"

/*
 * ��ȡ�������
 */
EXTERN_C PLUGINRUNTIME_API struct PluginMethod* GetPluginMethod(struct PluginRuntime* env, const char* name, const char* argv);

/*
 * ���ò������
 */
EXTERN_C PLUGINRUNTIME_API void CallPluginMethod(struct PluginRuntime* env, struct PluginMethod* method);

/*
 * ��ȡ�����ı�������
 */
EXTERN_C PLUGINRUNTIME_API int GetValuesCount(struct PluginMethod* method);

/*
 * ��������ı����б�
 */
EXTERN_C PLUGINRUNTIME_API void ClearValues(struct PluginMethod* method);


/*
 * ��ȡ�����ı�����ֵ
 */
EXTERN_C PLUGINRUNTIME_API struct PluginValue* GetValueAt(struct PluginMethod* method, int at);

/*
 * ��ȡ int ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API bool GetIntValue(struct PluginValue* value, int* ret);

/*
 * ��ȡ bool ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API bool GetBoolValue(struct PluginValue* value, bool* ret);

/*
 * ��ȡ char ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API bool GetCharValue(struct PluginValue* value, char* ret);

/*
 * ��ȡ float ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API bool GetFloatValue(struct PluginValue* value, float* ret);

/*
 * ��ȡ double ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API bool GetDoubleValue(struct PluginValue* value, double* ret);

/*
 * ��ȡ char* ���͵�ֵ�ĳ���
 */
EXTERN_C PLUGINRUNTIME_API int GetStringValueLength(struct PluginValue* value);

/*
 * ��ȡ char* ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API bool GetStringValue(struct PluginValue* value, char* str, int len);

/*
 * ��ȡ void* ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void* GetVoidPtrValue(struct PluginValue* value);


/*
 * ���� int ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushIntValue(struct PluginMethod* method, int value);

/*
 * ���� bool ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushBoolValue(struct PluginMethod* method, bool value);

/*
 * ���� char ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushCharValue(struct PluginMethod* method, char value);

/*
 * ���� float ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushFloatValue(struct PluginMethod* method, float value);

/*
 * ���� double ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushDoubleValue(struct PluginMethod* method, double value);

/*
 * ���� char* ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushStringValue(struct PluginMethod* method, const char* str, int len);

/*
 * ���� void* ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushVoidPtrValue(struct PluginMethod* method, void* value);

#endif /*Plugin_Runtime_H*/