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

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1、抽签
	this->speechDraw();

	//2、比赛

	//3、显示晋级结果

	//第二轮比赛

	//1、抽签
	this->speechDraw();

	//2、比赛

	//3、显示最终结果

	//4、保存分数
}

// 抽签
void SpeechManager::speechDraw()
{
	cout << "第 <<" << this->index << ">> 轮比赛选手正在抽签" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "抽签后的演讲顺序如下：" << endl;

	if (this->index == 1)
	{
		// 第一轮
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		// 第二轮
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << endl;

	system("pause");
	cout << endl;
}

SpeechManager::~SpeechManager()
{
}