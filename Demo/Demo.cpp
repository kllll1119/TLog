#include <iostream>

#define USE_TLOG_DYNAMIC

#include "../TLog/TLog.h"
//#pragma comment(lib,"..\\TLog\\TLog.lib")


int main(int argc, char *argv[])
{
	bool bDebug = false;

// 	std::cout << argc << std::endl;
// 	std::cout << argv[0] << std::endl;
// 
// 	if (argc < 2)
// 	{
// 		return 0;
// 	}
//  // 	TLog_Init("./", argv[1], TLOG_LV_DEBUG, 5, bDebug);
// 

	//初始化
	//int ret = TLog_Init("D:\\work_space\\TLog\\Release\\TLog.dll","./", "Demo", TLOG_LV_DEBUG , 2, bDebug);
	int ret = TLog_Init("D:\\work_space\\TLog\\TLog\\TLog.dll", "./", "Demo", TLOG_LV_DEBUG, 2, bDebug);
	printf("TLog_Init:%d\n", ret);
	ret = TLog_Print("hello Tlog...", 1);
	printf("TLog_Print:%d\n", ret);

	//打印测试
	TLog_Print(u8"hello tlog...测试", TLOG_LV_DEBUG);
	TLog_Print(u8"hello tlog...测试", TLOG_LV_INFO);
	TLog_Print(u8"hello tlog...测试", TLOG_LV_WAR);
	TLog_Print(u8"hello tlog...测试", TLOG_LV_ERR);

	TLog_Print(u8"这是一个测试\
		int TEXPORT_API GetPasswordStrength(string password); ", TLOG_LV_INFO);
	TLog_Print(u8R"({"account":[{"avatar":"http://wew23.png","client_mode":0,"id":123,"nick":"sss","phone":"2323","pid":4028,"user":"15293220","mode":0}],"account_count":1}
	)", TLOG_LV_INFO);
	TLog_Print(u8R"([accountmanagewnd.cpp:896 (15132) LV_INFO] DelAccountInfo:{"id":2323,"user_id":"996"})", TLOG_LV_INFO);
	
	system("pause");

	//释放资源
	TLog_UnInit();
}
