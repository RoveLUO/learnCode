/*

	功能描述：
	- 提供菜单界面与用户交互
	- 对演讲比赛流程进行控制
	- 与文件的读写交互

*/

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
using namespace std;

class speechManager {
public:
	speechManager();

	void showMenu();

	//退出系统
	void exitSyetem();

	//初始化容器和属性
	void initSpeech();

	//创建12名选手
	void createSpeaker();

	//开始比赛
	void startSpeech();

	//抽签
	void speechDraw();

	~speechManager();

	//成员属性
	//比赛选手 容器  12人
	vector<int>v1;

	//第一轮晋级容器  6人
	vector<int>v2;

	//胜利前三名容器  3人
	vector<int>vVictory;

	//存放编号 以及对应的 具体选手 容器
	map<int, Speaker> m_Speaker;

	//比赛轮数
	int m_Index;

};
