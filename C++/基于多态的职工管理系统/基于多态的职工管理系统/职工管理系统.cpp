#include <iostream>
#include "workerManager.h"

using namespace std;


int main() {
	

	


	//ʵ���������߶���
	WorkerManager workerManager;
	int choice = 0;

	while (true) {
		//չʾ�˵�
		workerManager.showMenu();
		cout << "���������ѡ��";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 0://�˳�ϵͳ
			workerManager.exitSystem();
			break;
		case 1://���ְ��
			workerManager.addEmp();
			break;
		case 2://��ʾְ��
			workerManager.showEmp();
			break;
		case 3: //ɾ��ְ��
			workerManager.delEmp();
			break;	
		case 4://�޸�ְ��
			workerManager.modEmp();
			break;
		case 5://����ְ��
			workerManager.findEmp();
			break;
		case 6://����ְ��
			workerManager.sortEmp();
			break;
		case 7://����ļ�
			workerManager.cleanFile();
			break;
		default:
			system("cls");
			break;
		}

	}

	
	return 0;
}