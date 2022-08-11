#pragma once
#include <iostream>
#include <string>
#include "worker.h"
using namespace std;

class Employee : public Worker {
public:

	Employee(int id, string name, int dID);
	//显示个人信息
	void showInfo();


	//获取岗位名称
	string getDepName();

	~Employee();
};