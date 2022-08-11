#include "workerManager.h"


/*
	�����ฺ����������£�
	���û��Ĺ�ͨ�˵�����
	��ְ����ɾ�Ĳ�Ĳ���
	���ļ��Ķ�д����
*/


WorkerManager :: WorkerManager() {

	//��ʼ������
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������\n";
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڵ��޼�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��\n";
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	ifs.close();

	//3.�ļ��������м�¼
	int num = this->getEmpNum();
	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->initEmp();
	/*for (int i = 0; i < this->m_EmpNum; i++) {
		cout << this->m_EmpArray[i]->m_ID << '\t'
			<< this->m_EmpArray[i]->m_Name << '\t'
			<< this->m_EmpArray[i]->m_DepID << endl;
	}*/
	
	
}

//չʾ�˵�
void WorkerManager :: showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager :: exitSystem() {
	cout << "��ӭ�´�ʹ�ã�\n";
	exit(0);
}

//���ְ��
void WorkerManager :: addEmp() {
	cout << "���������ְ��������";
	int addNum = 0;
	cin >> addNum;
	cout << endl;
	if (addNum > 0) {
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize+4];
		//��ԭ���ռ������ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++)
				newSpace[i] = this->m_EmpArray[i];
		}
		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;
			cout << "�������" << i + 1 << "����ְ����ţ�";
			cin >> id;
			cout << endl;

			cout << "�������" << i + 1 << "����ְ��������";
			cin >> name;
			cout << endl;

			cout << "��ѡ���ְ����λ��\n";
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			//������ְ��ְ�𣬱��浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//������ְ������
		this->m_EmpNum = newSize;
		//�������ݵ��ļ���
		this->save();
		m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "������������\n";
		system("pause");
		system("cls");
	}
}

//�����ļ�
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

//ͳ���ļ�������
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

//��ʼ��Ա��
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

//��ʾְ��
void WorkerManager :: showEmp() {
	if (this->m_EmpNum == 0) {
		cout << "�ļ�Ϊ�գ�\n";
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->showInfo();
		}
		system("pause");
		system("cls");
	}
}

//������ж�ְ���Ƿ����
int WorkerManager :: isExit(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (id == this->m_EmpArray[i]->m_ID)
			return i;
	}
	return -1;
}

//ɾ��ְ��
void WorkerManager :: delEmp() {
	cout << "�������ѯְ����ţ�";
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
		cout << "ɾ���ɹ���\n";
	}
	else {
		cout << "���޴��ˣ�\n";
		
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager :: modEmp() {
	cout << "�������޸�ְ����ţ�";
	int id;
	cin >> id;
	cout << endl;
	int index = this->isExit(id);
	if (index != -1) {
		int id;
		string name;
		int dSelect;
		cout << "������ְ����ţ�";
		cin>> id;
		cout << endl;

		cout << "������ְ��������";
		cin >> name;
		cout << endl;

		
		cout << "��ѡ���ְ����λ��\n";
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
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
		//������ְ��ְ�𣬱��浽������
		this->m_EmpArray[index] = worker;
		this->save();
		cout << "�޸ĳɹ���\n";
	}
	else {
		cout << "���޴��ˣ�\n";
	}
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager :: findEmp() {
	int select;
	cout << "�������ѯ��ʽ��\n";
	cout << "1---��ְ����Ų���\n";
	cout << "2---��ְ����������\n";
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "����������������룺";
		cin >> select;
	}
	if (select == 1) {//��ְ����Ų���
		cout << "�������ѯְ����ţ�";
		int id;
		cin >> id;
		cout << endl;
		int index = this->isExit(id);
		if (index != -1) {
			this->m_EmpArray[index]->showInfo();
		}
		else {
			cout << "���޴��ˣ�\n";
		}
	}
	else {//��ְ����������
		bool flag = false;
		cout << "�������ѯְ��������";
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
			cout << "���޴���\n";
	}
	system("pause");
	system("cls");
	

}

//����ְ��
void WorkerManager :: sortEmp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��\n";
		system("pause");
		system("cls");
	}
	else {
		int select;
		cout << "��ѡ������ʽ��\n";
		cout << "1---��ְ���������\n";
		cout << "2---��ְ����Ž���\n";
		cin >> select;

		while (select != 1 && select != 2) {
			cout << "�����������������룡\n";
			cin >> select;
		}

		for (int i = 0; i < this->m_EmpNum; i++) {
			int minOrMax = i; // ������Сֵ �� ���ֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) {//����
					if (this->m_EmpArray[minOrMax]->m_ID > this->m_EmpArray[j]->m_ID)
						minOrMax = j;
				}
				else {//����
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
		cout << "����ɹ��������Ľ��Ϊ��\n";
		this->save();
		this->showEmp();
	}
}

//����ļ�
void WorkerManager :: cleanFile() {
	int select;
	cout << "��ȷ���Ƿ����\n";
	cout << "1---ȷ��\n";
	cout << "2---����\n";
	cin >> select;

	while (select != 1 && select != 2) {
		cout << "�����������������룡\n";
		cin >> select;
	}

	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);//ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] == NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "��ճɹ�\n";
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
