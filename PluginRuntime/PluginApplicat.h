/*
 * ����ļ��ǹ���ͷ�ļ������뱻������
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
 * ����ı���ֵ����
 */
struct PluginValue;

/*
 * ���������ʱ����
 */
struct PluginMethod;

/*
 * ���������ʱ����
 */
struct PluginRuntime;

/*
 * ������Խ��ܵ�ע�ắ��
 */
typedef void(*PluginMethodPtr)(struct PluginMethod* method, void* object);

#endif /*Plugin_Applicat_H*/