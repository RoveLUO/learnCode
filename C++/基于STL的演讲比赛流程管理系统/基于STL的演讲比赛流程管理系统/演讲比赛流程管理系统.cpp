#include <iostream>
using namespace std;
#include "speechManager.h"

int main() {
	speechManager sm;
	int choice;

	

	while (true) {
		sm.showMenu();
		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��
		cout << endl;

		switch (choice)
		{
		case 1://��ʼ����
			sm.startSpeech();
			break;
		case 2://�鿴��¼
			break;
		case 3://��ռ�¼
			break;
		case 0://�˳�ϵͳ
			sm.exitSyetem();
			break;
		default:
			break;
		}	
		//system("pause");
	}

	

	return 0;
}