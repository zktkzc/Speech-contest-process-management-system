#include<iostream>
#include"SpeechManager.h"
using namespace std;

int main()
{

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
			break;
		case 2:  //查看记录
			break;
		case 3:  //清空记录
			break;
		case 0:  //退出系统
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	system("pause");
	return 0;
}