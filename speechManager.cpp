#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	// 初始化容器和属性
	this->initSpeech();

	// 创建12名选手
	this->createSpeaker();
}

void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// 退出系统
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

// 初始化容器和属性
void SpeechManager::initSpeech()
{
	// 容器都置空
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->speakers.clear();

	// 初始化比赛轮数
	this->index = 1;
}

// 创建比赛选手
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}

		//创建选手编号，并且放到v1容器中
		this->v1.push_back(i + 10001);

		// 将选手的编号以及对应的选手放入map容器中
		this->speakers.insert(make_pair(i + 10001, sp));
	}
}

SpeechManager::~SpeechManager()
{
}