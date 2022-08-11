#include <iostream>
#include "workerManager.h"

using namespace std;


int main() {
	

	


	//实例化管理者对象
	WorkerManager workerManager;
	int choice = 0;

	while (true) {
		//展示菜单
		workerManager.showMenu();
		cout << "请输入你的选择：";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 0://退出系统
			workerManager.exitSystem();
			break;
		case 1://添加职工
			workerManager.addEmp();
			break;
		case 2://显示职工
			workerManager.showEmp();
			break;
		case 3: //删除职工
			workerManager.delEmp();
			break;	
		case 4://修改职工
			workerManager.modEmp();
			break;
		case 5://查找职工
			workerManager.findEmp();
			break;
		case 6://排序职工
			workerManager.sortEmp();
			break;
		case 7://清空文件
			workerManager.cleanFile();
			break;
		default:
			system("cls");
			break;
		}

	}

	
	return 0;
}