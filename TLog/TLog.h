#pragma once

#ifdef IMPORT_TLOG_API
#define TLOG_API __declspec(dllimport)
#else
#define TLOG_API __declspec(dllexport)
#endif

#define	TLOG_LV_DEBUG 0
#define	TLOG_LV_INFO 1
#define	TLOG_LV_WAR 2
#define	TLOG_LV_ERR 3

extern "C"
{
	/*
	TLog_Init：日志初始化
	参数：folder:日志目录（建议绝对路径），base_name:日志名称,lv：打印日志等级，max_files最大保留日志个数，debug:是否调试模式（不加密）
	*/
	int TLOG_API TLog_Init(const char* folder, const char* base_name, int lv, int max_files, bool debug);

	/*
	TLog_Init：日志初始化
	参数：data:日志内容，lv：日志等级
	*/
	int TLOG_API TLog_Print(const char* data, int lv);

	/*
	TLog_Init：日志库释放资源
	*/
	void TLOG_API TLog_UnInit();
}


