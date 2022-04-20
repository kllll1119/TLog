// Demo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "../TLog/TLog.h"
#pragma comment(lib,"..\\Release\\TLog.lib")
#include <corecrt_io.h>
#include <Shlwapi.h>
#include <time.h>
#pragma comment(lib,"Shlwapi")

UINT64 GetTimeStampS()  //返回秒
{
	time_t t = time(NULL);
	return t;
}

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
	TLog_Init("./", "Demo", TLOG_LV_DEBUG , 2, bDebug);
	TLog_Print("hello Tlog...", 1);

	//打印测试
	TLog_Print(u8"hello tlog...测试", TLOG_LV_DEBUG);
	TLog_Print(u8"hello tlog...测试", TLOG_LV_INFO);
	TLog_Print(u8"hello tlog...测试", TLOG_LV_WAR);
	TLog_Print(u8"hello tlog...测试", TLOG_LV_ERR);

	TLog_Print(u8"这是一个测试\
		int TEXPORT_API GetPasswordStrength(string password); ", TLOG_LV_INFO);
	TLog_Print(u8R"({"account":[{"avatar":"http://wework.qpic.cn/bizmail/9wt86APtVAia0L4PdzLONQXLibk5ao578hWp8iaTF5IYjCPk4EUS9MVXA/0","client_mode":0,"company_name":"成都晓多科技有限公司","id":1688850456160424,"nick":"唐磊","phone":"13982104923","pid":4028,"power_enter_mp":false,"user_id":"155960420","work_mode":0}],"account_count":1}
	)", TLOG_LV_INFO);
	TLog_Print(u8R"([accountmanagewnd.cpp:896 (15132) LV_INFO] DelAccountInfo:{"id":1688850456160424,"user_id":"155960420"})", TLOG_LV_INFO);
	
	system("pause");

	//释放资源
	TLog_UnInit();
}
