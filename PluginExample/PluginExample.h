// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� PLUGINEXAMPLE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// PLUGINEXAMPLE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef PLUGINEXAMPLE_EXPORTS
#define PLUGINEXAMPLE_API __declspec(dllexport)
#else
#define PLUGINEXAMPLE_API __declspec(dllimport)
#endif

#include "../PluginRuntime/PluginRuntime.h"

extern "C" PLUGINEXAMPLE_API void OnPluginLoad(struct PluginRuntime* env);

extern "C" PLUGINEXAMPLE_API void Call();