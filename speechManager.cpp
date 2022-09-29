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
	this->speechContest();

	//3、显示晋级结果
	this->showScore();

	//第二轮比赛
	this->index++;

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示最终结果
	this->showScore();

	//4、保存分数
	this->saveRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

// 抽签
void SpeechManager::speechDraw()
{
	cout << "第 << " << this->index << " >> 轮比赛选手正在抽签" << endl;
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

// 比赛
void SpeechManager::speechContest()
{
	cout << "--------第" << this->index << "轮比赛正式开始--------" << endl;

	// 准备临时容器存放小组成绩
	multimap <double, int, greater<double>> groupScore;

	int num = 0; // 记录人员个数，6人一组

	vector<int> v_Src; // 比赛选手容器
	if (this->index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// 遍历所有参赛选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// 评委打分
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 600 ~ 1000
			// cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>()); // 降序排序
		d.pop_front(); // 去除最高分
		d.pop_back(); // 去除最低分

		double sum = accumulate(d.begin(), d.end(), 0); // 总分
		double avg = sum / (double)d.size(); // 平均分

		// 打印平均分
		//cout << "编号：" << *it << " 姓名：" << this->speakers[*it].name << " 平均分：" << avg << endl;

		// 将平均分放入map容器中
		this->speakers[*it].score[this->index - 1] = avg;

		// 将打分的数据放入临时的小组容器中
		groupScore.insert(make_pair(avg, *it)); // key是得分，value是具体的选手的编号
		// 每六人去除前三名
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组的比赛名次如下：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号：" << it->second << " 姓名：" << this->speakers[it->second].name << " 成绩：" << this->speakers[it->second].score[this->index - 1] << endl;
			}

			// 取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					vVictory.push_back((*it).second);
				}
			}

			groupScore.clear(); // 清空小组容器

			cout << endl;
		}
	}

	cout << "--------第" << this->index << "轮比赛完毕!--------" << endl;
	system("pause");
	cout << endl;
}

// 显示比赛结果
void SpeechManager::showScore()
{
	cout << "--------第" << this->index << "轮晋级的选手信息如下：--------" << endl;

	vector<int> v;
	if (this->index == 1)
	{
		v = v2;
	}
	else
	{
		v = vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "选手编号：" << *it << " 姓名：" << this->speakers[*it].name << " 得分：" << this->speakers[*it].score[this->index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();
}

// 保存记录
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用追加的方式写文件

	// 将每个选手的数据写入到容器中
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->speakers[*it].score[1] << ",";
	}
	ofs << endl;

	// 关闭文件
	ofs.close();

	cout << "记录保存完毕！" << endl;
}

SpeechManager::~SpeechManager()
{
}