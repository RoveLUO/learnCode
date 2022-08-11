#include "speechManager.h"

speechManager :: speechManager() {
	this->initSpeech();
	this->createSpeaker();
}

void speechManager :: showMenu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void speechManager :: exitSyetem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������
void speechManager :: initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
}

//����12��ѡ��
void speechManager :: createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "ѡ��";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++) {
			sp.m_score[j] = 0;
		}

		this->v1.push_back(10001+i);
		this->m_Speaker.insert(make_pair((i + 10001), sp));
	}
}

//��ʼ����
void speechManager :: startSpeech() {
	//��һ�ֿ�ʼ����
	//1.��ǩ
	this->speechDraw();
	//2.����
	//3.��ʾ�������
	
	//�ڶ��ֿ�ʼ����
	//1.��ǩ
	//2.����
	//3.��ʾ���ս��
	//4.���浽�ļ�
}

//��ǩ
void speechManager :: speechDraw() {
	cout << "�� <" << this->m_Index << ">�ֱ���ѡ�����ڳ�ǩ��" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

	}
	cout << "--------------------------------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

speechManager :: ~speechManager() {

}