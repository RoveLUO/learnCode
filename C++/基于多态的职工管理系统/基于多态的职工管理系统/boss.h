#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Boss : public Worker {
public:

	Boss(int id, string name, int dID);
	//��ʾ������Ϣ
	void showInfo();


	//��ȡ��λ����
	string getDepName();

	~Boss();
};