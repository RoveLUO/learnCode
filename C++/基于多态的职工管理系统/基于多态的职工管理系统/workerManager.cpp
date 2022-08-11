#include "workerManager.h"


/*
	管理类负责的内容如下：
	与用户的沟通菜单界面
	对职工增删改查的操作
	与文件的读写交互
*/


WorkerManager :: WorkerManager() {

	//初始化属性
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在\n";
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在但无记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空\n";
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	ifs.close();

	//3.文件存在且有记录
	int num = this->getEmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->initEmp();
	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << this->m_EmpArray[i]->m_ID << '\t'
			<< this->m_EmpArray[i]->m_Name << '\t'
			<< this->m_EmpArray[i]->m_DepID << endl;
	}*/
	
	
}

//展示菜单
void WorkerManager :: showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager :: exitSystem() {
	cout << "欢迎下次使用！\n";
	exit(0);
}

//添加职工
void WorkerManager :: addEmp() {
	cout << "请输入添加职工数量：";
	int addNum = 0;
	cin >> addNum;
	cout << endl;
	if (addNum > 0) {
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize+4];
		//将原来空间下数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}
		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "请输入第" << i + 1 << "个新职工编号：";
			cin >> id;
			cout << endl;

			cout << "请输入第" << i + 1 << "个新职工姓名：";
			cin >> name;
			cout << endl;

			cout << "请选择该职工岗位：\n";
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			cout << endl;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建职工职责，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更改新职工人数
		this->m_EmpNum = newSize;
		//保存数据到文件中
		this->save();
		m_FileIsEmpty = false;
		cout << "成功添加" << addNum << "名新职工" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "输入数据有误\n";
		system("pause");
		system("cls");
	}
}

//保存文件
void WorkerManager :: save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << "\t"
			<< this->m_EmpArray[i]->m_Name << "\t"
			<< this->m_EmpArray[i]->m_DepID << endl;
	}
	ofs.close();
}

//统计文件中人数
int WorkerManager :: getEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	ifs.close();
	return num;
}

//初始化员工
void WorkerManager :: initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	int index = 0;
	Worker* worker;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//显示职工
void WorkerManager :: showEmp() {
	if (this->m_EmpNum == 0) {
		cout << "文件为空！\n";
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
		system("pause");
		system("cls");
	}
}

//按编号判断职工是否存在
int WorkerManager :: isExit(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (id == this->m_EmpArray[i]->m_ID)
			return i;
	}
	return -1;
}

//删除职工
void WorkerManager :: delEmp() {
	cout << "请输入查询职工编号：";
	int id;
	cin >> id;
	cout << endl;
	int index = this->isExit(id);
	if (index != -1) {
		for (; index < this->m_EmpNum-1; index++) {
			this->m_EmpArray[index] = this->m_EmpArray[index + 1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "删除成功！\n";
	}
	else {
		cout << "查无此人！\n";
		
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkerManager :: modEmp() {
	cout << "请输入修改职工编号：";
	int id;
	cin >> id;
	cout << endl;
	int index = this->isExit(id);
	if (index != -1) {
		int id;
		string name;
		int dSelect;
		cout << "请输入职工编号：";
		cin>> id;
		cout << endl;

		cout << "请输入职工姓名：";
		cin >> name;
		cout << endl;

		
		cout << "请选择该职工岗位：\n";
		cout << "1、普通职工" << endl;
		cout << "2、经理" << endl;
		cout << "3、老板" << endl;
		cin >> dSelect;
		cout << endl;

		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		//将创建职工职责，保存到数组中
		this->m_EmpArray[index] = worker;
		this->save();
		cout << "修改成功！\n";
	}
	else {
		cout << "查无此人！\n";
	}
	system("pause");
	system("cls");
}

//查找职工
void WorkerManager :: findEmp() {
	int select;
	cout << "请输入查询方式：\n";
	cout << "1---按职工编号查找\n";
	cout << "2---按职工姓名查找\n";
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "输入错误请重新输入：";
		cin >> select;
	}
	if (select == 1) {//按职工编号查找
		cout << "请输入查询职工编号：";
		int id;
		cin >> id;
		cout << endl;
		int index = this->isExit(id);
		if (index != -1) {
			this->m_EmpArray[index]->showInfo();
		}
		else {
			cout << "查无此人！\n";
		}
	}
	else {//按职工姓名查找
		bool flag = false;
		cout << "请输入查询职工姓名：";
		string name;
		cin >> name;
		cout << endl;
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i]->m_Name == name) {
				this->m_EmpArray[i]->showInfo();
				flag = true;
			}
		}
		if (flag == false)
			cout << "查无此人\n";
	}
	system("pause");
	system("cls");
	

}

//排序职工
void WorkerManager :: sortEmp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空\n";
		system("pause");
		system("cls");
	}
	else {
		int select;
		cout << "请选择排序方式：\n";
		cout << "1---按职工编号升序\n";
		cout << "2---按职工编号降序\n";
		cin >> select;

		while (select != 1 && select != 2) {
			cout << "输入有误，请重新输入！\n";
			cin >> select;
		}

		for (int i = 0; i < this->m_EmpNum; i++) {
			int minOrMax = i; // 声明最小值 或 最大值下标
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//升序
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
						minOrMax = j;
				}
				else {//降序
					if (this->m_EmpArray[minOrMax]->m_ID < this->m_EmpArray[j]->m_ID)
						minOrMax = j;
				}
			}
			if (i != minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "排序成功，排序后的结果为：\n";
		this->save();
		this->showEmp();
	}
}

//清空文件
void WorkerManager :: cleanFile() {
	int select;
	cout << "请确认是否清空\n";
	cout << "1---确定\n";
	cout << "2---返回\n";
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "输入有误，请重新输入！\n";
		cin >> select;
	}

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] == NULL;
			}
			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功\n";
	}
	system("pause");
	system("cls");
}

WorkerManager :: ~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] == NULL;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
