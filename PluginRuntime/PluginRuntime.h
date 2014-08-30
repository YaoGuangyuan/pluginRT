/**
 * ���ͷ�ļ����ͻ��˿���ʹ�á�
 */

#ifndef Plugin_Runtime_H
#define Plugin_Runtime_H

#include "PluginApplicat.h"

/**
 * ��ȡ�������ʱ����
 * 
 * @Param env
 *        ����ʱ����
 * @Param yclass
 *        ���������
 * @Param name
 *        ���������
 * @Return ���ض�����
 */
EXTERN_C PLUGINRUNTIME_API void* GetPluginObject(PluginRuntime* env, const char* yclass, const char* name);

/**
 * ��ȡ�������
 * 
 * @Param env
 *        ����ʱ����
 * @Param name
 *        ��������
 * @Param argv
 *        ���������б�
 * @Return ���ط������
 */
EXTERN_C PLUGINRUNTIME_API PluginMethod* GetPluginMethod(PluginRuntime* env, const char* name, const char* argv);

/**
 * ���ò������
 * 
 * @Param env
 *        ����ʱ����
 * @Param method
 *        �������
 * @Param obj
 *        ������
 * @Return ���ؽ��ֵ
 */
EXTERN_C PLUGINRUNTIME_API PluginValue* CallPluginMethod(PluginRuntime* env, PluginMethod* method, void* obj, PluginValue* arg);

/**
 * ��ȡֵ���
 * 
 * @Return ���ط���õ�ֵ���
 */
EXTERN_C PLUGINRUNTIME_API PluginValue* MallocValue();

/**
 * �ͷ�ֵ���
 *
 * @Param value
 *        ֵ���
 */
EXTERN_C PLUGINRUNTIME_API void ReleaseValue(PluginValue* value);

/**
 * ��ȡ�����ĸ���
 *
 * @Param value
 *        ֵ���
 * @Return ����ֵ������
 */
EXTERN_C PLUGINRUNTIME_API uint32_t GetValueCount(PluginValue* value);

/**
 * ��ȡ bool ('b') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        boolֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetBoolValue(PluginValue* value, uint32_t at, bool* ret);

/**
 * ��ȡ byte ('B') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        byteֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetByteValue(PluginValue* value, uint32_t at, unsigned char* ret);

/**
 * ��ȡ short ('h') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        shortֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetShortValue(PluginValue* value, uint32_t at, short* ret);

/**
 * ��ȡ unsigned short ('H') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        unsigned shortֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedShortValue(PluginValue* value, uint32_t at, unsigned short* ret);

/**
 * ��ȡ int ('i') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        intֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetIntValue(PluginValue* value, uint32_t at, int* ret);

/**
 * ��ȡ unsigned int ('I') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        unsigned intֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedIntValue(PluginValue* value, uint32_t at, unsigned int* ret);

/**
 * ��ȡ long ('l') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        longֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetLongValue(PluginValue* value, uint32_t at, long* ret);

/**
 * ��ȡ unsigned long ('k') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        unsigned longֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedLongValue(PluginValue* value, uint32_t at, unsigned long* ret);

/**
 * ��ȡ long long ('L') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        long longֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetLongLongValue(PluginValue* value, uint32_t at, long long* ret);

/**
 * ��ȡ unsigned long long ('K') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        unsigned long longֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetUnsignedLongLongValue(PluginValue* value, uint32_t at, unsigned long long* ret);

/**
 * ��ȡ float ('f') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        floatֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetFloatValue(PluginValue* value, uint32_t at, float* ret);

/**
 * ��ȡ double ('d') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        doubleֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetDoubleValue(PluginValue* value, uint32_t at, double* ret);

/**
 * ��ȡ char ('c') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param ret
 *        charֵָ��
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetCharValue(PluginValue* value, uint32_t at, char* ret);

/**
 * ��ȡ char* ('s') ���͵�ֵ�ĳ���
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Return �����ַ����ĳ���
 */
EXTERN_C PLUGINRUNTIME_API uint32_t GetStringValueLength(PluginValue* value, uint32_t at);

/**
 * ��ȡ char* ('s') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Param str
 *        �ַ����ڴ�ָ��
 * @Param len
 *        �ַ�������
 * @Return �����Ƿ�ɹ�
 */
EXTERN_C PLUGINRUNTIME_API bool GetStringValue(PluginValue* value, uint32_t at, char* str, uint32_t len);

/**
 * ��ȡ void* ('p') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param at
 *        ֵ������
 * @Return ���� void* ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void* GetVoidPtrValue(PluginValue* value, uint32_t at);

/**
 * ���� bool ('b') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        bool ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushBoolValue(PluginValue* value, bool vl);

/**
 * ���� byte ('B') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        byte ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushByteValue(PluginValue* value, unsigned char vl);

/**
 * ���� short ('h') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        short ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushShortValue(PluginValue* value, short vl);

/**
 * ���� unsigned short ('H') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        unsigned short ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedShortValue(PluginValue* value, unsigned short vl);

/**
 * ���� int ('i') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        int ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushIntValue(PluginValue* value, int vl);

/**
 * ���� unsigned int ('I') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        unsigned int ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedIntValue(PluginValue* value, unsigned int vl);

/**
 * ���� long ('l') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        long ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushLongValue(PluginValue* value, long vl);

/**
 * ���� unsigned long ('k') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        unsigned long ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedLongValue(PluginValue* value, unsigned long vl);

/**
 * ���� long long ('L') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        long long ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushLongLongValue(PluginValue* value, long long vl);

/**
 * ���� unsigned long long ('K') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        unsigned long long ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushUnsignedLongLongValue(PluginValue* value, unsigned long long vl);

/**
 * ���� float ('f') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        float ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushFloatValue(PluginValue* value, float vl);

/**
 * ���� double ('d') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        double ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushDoubleValue(PluginValue* value, double vl);

/**
 * ���� char ('c') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        char ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushCharValue(PluginValue* value, char vl);

/**
 * ���� char* ('s') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param str
 *        �ַ������ڴ�ָ��
 * @Param len
 *        �ַ����ĳ���
 */
EXTERN_C PLUGINRUNTIME_API void PushStringValue(PluginValue* value, const char* str, uint32_t len);

/**
 * ���� void* ('p') ���͵�ֵ
 * 
 * @Param value
 *        ����ֵ�ľ��
 * @Param value
 *        void* ���͵�ֵ
 */
EXTERN_C PLUGINRUNTIME_API void PushVoidPtrValue(PluginValue* value, void* vl);

#endif /*Plugin_Runtime_H*/