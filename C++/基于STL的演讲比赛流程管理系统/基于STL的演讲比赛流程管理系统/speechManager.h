/*

	����������
	- �ṩ�˵��������û�����
	- ���ݽ��������̽��п���
	- ���ļ��Ķ�д����

*/

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
using namespace std;

class speechManager {
public:
	speechManager();

	void showMenu();

	//�˳�ϵͳ
	void exitSyetem();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeaker();

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	~speechManager();

	//��Ա����
	//����ѡ�� ����  12��
	vector<int>v1;

	//��һ�ֽ�������  6��
	vector<int>v2;

	//ʤ��ǰ��������  3��
	vector<int>vVictory;

	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;

	//��������
	int m_Index;

};
