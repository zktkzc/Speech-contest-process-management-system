#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<functional>
#include<algorithm>
#include<numeric>
#include<string>
#include<fstream>
#include"Speaker.h"
using namespace std;

// 演讲管理类
class SpeechManager
{
public:

	SpeechManager();

	void showMenu();

	//退出系统
	void exitSystem();

	// 初始化容器和属性
	void initSpeech();

	// 创建比赛选手
	void createSpeaker();

	//开始比赛
	void startSpeech();

	// 抽签
	void speechDraw();

	// 比赛
	void speechContest();

	// 显示比赛结果
	void showScore();

	// 保存记录
	void saveRecord();

	// 读取记录
	void loadRecord();

	// 显示往届记录
	void showRecord();

	// 清空记录
	void clearRecord();

	~SpeechManager();

	// 第一轮选手比赛编号容器
	vector<int> v1;

	// 第一轮晋级的选手编号容器
	vector<int> v2;

	// 胜出的前三名的选手编号容器
	vector<int> vVictory;

	// 存放编号以及对应的选手的容器
	map<int, Speaker> speakers;

	// 存放比赛轮数
	int index;

	// 文件为空的标志
	bool fielIsEmpty;

	// 往届记录
	map<int, vector<string>> record;
};

