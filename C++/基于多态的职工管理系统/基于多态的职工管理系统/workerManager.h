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

	//չʾ�˵�
	void showMenu();

	//�˳�ϵͳ
	void exitSystem();

	//���ְ��
	void addEmp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�ձ�־
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int getEmpNum();

	//��ʼ��Ա��
	void initEmp();

	//��ʾְ��
	void showEmp();

	//������ж�ְ���Ƿ����
	int isExit(int id);

	//ɾ��ְ��
	void delEmp();

	//�޸�ְ��
	void modEmp();

	//����ְ��
	void findEmp();

	//����ְ��
	void sortEmp();

	//����ļ�
	void cleanFile();



	//��¼ְ������
	int  m_EmpNum;
	//ְ������ָ��
	Worker ** m_EmpArray;

	~WorkerManager();
};