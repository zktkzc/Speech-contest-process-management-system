#include<iostream>
#include<ctime>
#include"SpeechManager.h"
using namespace std;

int main()
{
	// 添加随机数种子
	srand((unsigned int)time(NULL));

	SpeechManager sm;

	int choice = 0; //用来存储用户的选项

	while (true)
	{
		sm.showMenu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接收用户的输入

		switch (choice)
		{
		case 1:  //开始比赛
			sm.startSpeech();
			break;
		case 2:  //查看记录
			sm.showRecord();
			break;
		case 3:  //清空记录
			sm.clearRecord();
			break;
		case 0:  //退出系统
			sm.exitSystem();
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	system("pause");
	return 0;
}