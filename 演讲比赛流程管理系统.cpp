#include<iostream>
#include"SpeechManager.h"
using namespace std;

int main()
{

	SpeechManager sm;

	int choice = 0; //�����洢�û���ѡ��

	while (true)
	{
		sm.showMenu();

		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û�������

		switch (choice)
		{
		case 1:  //��ʼ����
			break;
		case 2:  //�鿴��¼
			break;
		case 3:  //��ռ�¼
			break;
		case 0:  //�˳�ϵͳ
			break;
		default:
			system("cls"); //����
			break;
		}
	}

	system("pause");
	return 0;
}