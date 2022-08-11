#include <iostream>
using namespace std;
#include "speechManager.h"

int main() {
	speechManager sm;
	int choice;

	

	while (true) {
		sm.showMenu();
		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项
		cout << endl;

		switch (choice)
		{
		case 1://开始比赛
			sm.startSpeech();
			break;
		case 2://查看记录
			break;
		case 3://清空记录
			break;
		case 0://退出系统
			sm.exitSyetem();
			break;
		default:
			break;
		}	
		//system("pause");
	}

	

	return 0;
}