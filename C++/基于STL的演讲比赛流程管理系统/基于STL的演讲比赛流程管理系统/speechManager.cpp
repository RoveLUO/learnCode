#include "speechManager.h"

speechManager :: speechManager() {
	this->initSpeech();
	this->createSpeaker();
}

void speechManager :: showMenu() {
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出系统
void speechManager :: exitSyetem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//初始化属性
void speechManager :: initSpeech() {
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
}

//创建12名选手
void speechManager :: createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_name = name;

		for (int j = 0; j < 2; j++) {
			sp.m_score[j] = 0;
		}

		this->v1.push_back(10001+i);
		this->m_Speaker.insert(make_pair((i + 10001), sp));
	}
}

//开始比赛
void speechManager :: startSpeech() {
	//第一轮开始比赛
	//1.抽签
	this->speechDraw();
	//2.比赛
	//3.显示晋级结果
	
	//第二轮开始比赛
	//1.抽签
	//2.比赛
	//3.显示最终结果
	//4.保存到文件
}

//抽签
void speechManager :: speechDraw() {
	cout << "第 <" << this->m_Index << ">轮比赛选手正在抽签！" << endl;
	cout << "--------------------------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

	if (this->m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;

	}
	cout << "--------------------------------------------------------------------" << endl;
	system("pause");
	cout << endl;
}

speechManager :: ~speechManager() {

}