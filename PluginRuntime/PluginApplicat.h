/**
 * ����ļ��ǹ���ͷ�ļ������뱻������
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
 * ����ı���ֵ����
 */
struct PluginValue;

/**
 * ���������ʱ����
 */
struct PluginMethod;

/**
 * ���������ʱ����
 */
struct PluginRuntime;

/**
 * ���庯��ԭ��
 * 
 * @Param method
 *        ����ʱ����
 * @Param object
 *        �Զ���ͻ��˶���
 * @Param arg
 *        ����ʱ�����Ĳ���
 * @Return ����ֵ�ľ��
 */
typedef PluginValue* (*PluginMethodPtr) (PluginMethod* method, void* object, PluginValue* arg);

/********************************************************************/
/*                       ��������������                             */
/*																	*/
/*  ���ͼ�д	��������				������������				*/
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