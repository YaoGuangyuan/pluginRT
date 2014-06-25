#ifndef Plugin_Runtime_0_H
#define Plugin_Runtime_0_H

#include "PluginApplicat.h"

/*
 * ����һ������ʱ����
 */
EXTERN_C PLUGINRUNTIME_API struct PluginRuntime* CreatePluginRuntime(const char* id);

/*
 * ɾ��һ������ʱ����
 */
EXTERN_C PLUGINRUNTIME_API void DeletePluginRuntime(struct PluginRuntime** env);

/*
 * ע������ʱ�����ľ��
 */
struct PluginMethodHandle
{
	char*			name;	// ��������
	char*			argv;	// �����б�
	PluginMethodPtr method;	// ����ָ��
	void*			object;	// ����ָ��
};

/*
 * ע������ʱ����
 */
EXTERN_C PLUGINRUNTIME_API bool RegisterPluginMethod(struct PluginRuntime* env, struct PluginMethodHandle handle);

#endif /*Plugin_Runtime_0_H*/