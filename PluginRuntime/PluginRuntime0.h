/**
 * ���ͷ�ļ�������˿���ʹ�á�
 */

#ifndef Plugin_Runtime_0_H
#define Plugin_Runtime_0_H

#include "PluginApplicat.h"

/**
 * ����һ������ʱ����
 * 
 * @Param id
 *        ����ʱ������ID
 * @Return ��������ʱ����
 */
EXTERN_C PLUGINRUNTIME_API PluginRuntime* CreatePluginRuntime(const char* id);

/**
 * ɾ��һ������ʱ����
 * 
 * @Param env
 *        ����ʱ�����ģ�������ָ��
 */
EXTERN_C PLUGINRUNTIME_API void DeletePluginRuntime(PluginRuntime** env);

/**
 * ע������ʱ�����ľ��
 */
struct PluginMethodHandle
{
	char*			name;	// ��������
	char*			argv;	// �����б�
	PluginMethodPtr method;	// ����ָ��
};

/**
 * ע������ʱ����
 * 
 * @Param env
 *        ����ʱ����
 * @Param handle
 *        ע�ắ�����
 * @Return �����Ƿ�ɹ�ע��
 */
EXTERN_C PLUGINRUNTIME_API bool RegisterPluginMethod(PluginRuntime* env, PluginMethodHandle handle);

/**
 * ע������ʱ����ľ��
 */
struct PluginObjectHandle
{
	char* yclass;	// ��������
	char* name;		// ��������
	void* object;	// ����ָ��
};

/**
 * ע������ʱ����
 * 
 * @Param env
 *        ����ʱ����
 * @Param handle
 *        ע�������
 * @Return �����Ƿ�ɹ�ע��
 */
EXTERN_C PLUGINRUNTIME_API bool RegisterPluginObject(PluginRuntime* env, PluginObjectHandle handle);

#endif /*Plugin_Runtime_0_H*/