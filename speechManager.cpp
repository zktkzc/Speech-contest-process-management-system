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
	this->speechContest();

	//3����ʾ�������
	this->showScore();

	//�ڶ��ֱ���
	this->index++;

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3����ʾ���ս��
	this->showScore();

	//4���������
	this->saveRecord();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

// ��ǩ
void SpeechManager::speechDraw()
{
	cout << "�� << " << this->index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
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

// ����
void SpeechManager::speechContest()
{
	cout << "--------��" << this->index << "�ֱ�����ʽ��ʼ--------" << endl;

	// ׼����ʱ�������С��ɼ�
	multimap <double, int, greater<double>> groupScore;

	int num = 0; // ��¼��Ա������6��һ��

	vector<int> v_Src; // ����ѡ������
	if (this->index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	// �������в���ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		// ��ί���
		deque<double> d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f; // 600 ~ 1000
			// cout << score << " ";
			d.push_back(score);
		}
		//cout << endl;

		sort(d.begin(), d.end(), greater<double>()); // ��������
		d.pop_front(); // ȥ����߷�
		d.pop_back(); // ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0); // �ܷ�
		double avg = sum / (double)d.size(); // ƽ����

		// ��ӡƽ����
		//cout << "��ţ�" << *it << " ������" << this->speakers[*it].name << " ƽ���֣�" << avg << endl;

		// ��ƽ���ַ���map������
		this->speakers[*it].score[this->index - 1] = avg;

		// ����ֵ����ݷ�����ʱ��С��������
		groupScore.insert(make_pair(avg, *it)); // key�ǵ÷֣�value�Ǿ����ѡ�ֵı��
		// ÿ����ȥ��ǰ����
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��ı����������£�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "��ţ�" << it->second << " ������" << this->speakers[it->second].name << " �ɼ���" << this->speakers[it->second].score[this->index - 1] << endl;
			}

			// ȡ��ǰ����
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

			groupScore.clear(); // ���С������

			cout << endl;
		}
	}

	cout << "--------��" << this->index << "�ֱ������!--------" << endl;
	system("pause");
	cout << endl;
}

// ��ʾ�������
void SpeechManager::showScore()
{
	cout << "--------��" << this->index << "�ֽ�����ѡ����Ϣ���£�--------" << endl;

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
		cout << "ѡ�ֱ�ţ�" << *it << " ������" << this->speakers[*it].name << " �÷֣�" << this->speakers[*it].score[this->index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->showMenu();
}

// �����¼
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ��׷�ӵķ�ʽд�ļ�

	// ��ÿ��ѡ�ֵ�����д�뵽������
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << this->speakers[*it].score[1] << ",";
	}
	ofs << endl;

	// �ر��ļ�
	ofs.close();

	cout << "��¼������ϣ�" << endl;
}

SpeechManager::~SpeechManager()
{
}