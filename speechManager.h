#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include"Speaker.h"
using namespace std;

// �ݽ�������
class SpeechManager
{
public:

	SpeechManager();

	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	// ��ʼ������������
	void initSpeech();

	// ��������ѡ��
	void createSpeaker();

	//��ʼ����
	void startSpeech();

	// ��ǩ
	void speechDraw();

	~SpeechManager();

	// ��һ��ѡ�ֱ����������
	vector<int> v1;

	// ��һ�ֽ�����ѡ�ֱ������
	vector<int> v2;

	// ʤ����ǰ������ѡ�ֱ������
	vector<int> vVictory;

	// ��ű���Լ���Ӧ��ѡ�ֵ�����
	map<int, Speaker> speakers;

	// ��ű�������
	int index;
};

