#pragma once
#include <iostream>
#include <fstream>
using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

#define FILENAME "empFile.txt"



class WorkerManager {

public:
	WorkerManager();

	//展示菜单
	void showMenu();

	//退出系统
	void exitSystem();

	//添加职工
	void addEmp();

	//保存文件
	void save();

	//判断文件是否为空标志
	bool m_FileIsEmpty;

	//统计文件中人数
	int getEmpNum();

	//初始化员工
	void initEmp();

	//显示职工
	void showEmp();

	//按编号判断职工是否存在
	int isExit(int id);

	//删除职工
	void delEmp();

	//修改职工
	void modEmp();

	//查找职工
	void findEmp();

	//排序职工
	void sortEmp();

	//清空文件
	void cleanFile();



	//记录职工人数
	int  m_EmpNum;
	//职工数组指针
	Worker ** m_EmpArray;

	~WorkerManager();
};