#include "SpeechManager.h"

SpeechManager::SpeechManager()
{
	// ��ʼ������������
	this->initSpeech();

	// ����12��ѡ��
	this->createSpeaker();
}

void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// �˳�ϵͳ
void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

// ��ʼ������������
void SpeechManager::initSpeech()
{
	// �������ÿ�
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->speakers.clear();

	// ��ʼ����������
	this->index = 1;
}

// ��������ѡ��
void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}

		//����ѡ�ֱ�ţ����ҷŵ�v1������
		this->v1.push_back(i + 10001);

		// ��ѡ�ֵı���Լ���Ӧ��ѡ�ַ���map������
		this->speakers.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1����ǩ
	this->speechDraw();

	//2������

	//3����ʾ�������

	//�ڶ��ֱ���

	//1����ǩ
	this->speechDraw();

	//2������

	//3����ʾ���ս��

	//4���������
}

// ��ǩ
void SpeechManager::speechDraw()
{
	cout << "�� <<" << this->index << ">> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "--------------------------------------------" << endl;
	cout << "��ǩ����ݽ�˳�����£�" << endl;

	if (this->index == 1)
	{
		// ��һ��
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		// �ڶ���
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