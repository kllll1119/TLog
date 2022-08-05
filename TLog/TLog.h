#pragma once

#define TLOG_API __declspec(dllexport)

#define	TLOG_LV_DEBUG 0
#define	TLOG_LV_INFO 1
#define	TLOG_LV_WAR 2
#define	TLOG_LV_ERR 3

#ifdef USE_TLOG_DYNAMIC
#include <Windows.h>
typedef int (WINAPI *TLOG_INIT_FUNC)(const char*, const char*, const char*, int, int, bool);
typedef int (WINAPI *TLOG_PRINT_FUNC)(const char* data, int lv);
typedef int (WINAPI *TLOG_UNINIT_FUNC)();
static HMODULE g_tlogModule = 0;
int TLog_Init(const char* dllPath, const char* folder, const char* base_name, int lv, int max_files, bool debug)
{
	g_tlogModule = LoadLibraryA(dllPath);
	if (g_tlogModule)
	{
		TLOG_INIT_FUNC excFunc = (TLOG_INIT_FUNC)GetProcAddress(g_tlogModule, "TLog_Init");
		if (excFunc)
		{
			return excFunc(dllPath, folder, base_name, lv, max_files, debug);
		}
	}
	return 0;
}
int TLog_Print(const char* data, int lv)
{
	if (g_tlogModule)
	{
		TLOG_PRINT_FUNC excFunc = (TLOG_PRINT_FUNC)GetProcAddress(g_tlogModule, "TLog_Print");
		if (excFunc)
		{
			return excFunc(data, lv);
		}
	}
	return 0;
}
void TLog_UnInit()
{
	TLOG_UNINIT_FUNC excFunc = (TLOG_UNINIT_FUNC)GetProcAddress(g_tlogModule, "TLog_UnInit");
	if (excFunc)
	{
		excFunc();
	}
	FreeLibrary(g_tlogModule);
	g_tlogModule = 0;
}
#else
extern "C"
{
	/*
	TLog_Init：日志初始化
	参数：
	dllPath: dll路径（建议绝对路径）
	folder: 日志目录（建议绝对路径）
	base_name: 日志名称
	lv: 打印日志等级
	max_files: 最大保留日志个数
	debug: 是否调试模式（true不加密）
	*/
	int TLOG_API TLog_Init(const char* dllPath, const char* folder, const char* base_name, int lv, int max_files, bool debug);

	/*
	TLog_Init：日志初始化
	参数：
	data: 日志内容
	lv: 日志等级
	*/
	int TLOG_API TLog_Print(const char* data, int lv);

	/*
	TLog_Init：日志库释放资源
	*/
	void TLOG_API TLog_UnInit();
}
#endif
