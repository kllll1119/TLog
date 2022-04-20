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
	int TLOG_API TLog_Init(const char* folder, const char* base_name, int lv, int max_files, bool debug);
	int TLOG_API TLog_Print(const char* data, int lv);
	void TLOG_API TLog_UnInit();
}


