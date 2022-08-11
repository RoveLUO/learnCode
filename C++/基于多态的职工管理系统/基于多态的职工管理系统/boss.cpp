#include "boss.h"

Boss::Boss(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepID = dID;
}

//显示个人信息
void Boss::showInfo() {
	cout << "职工编号：" << this->m_ID
		<< "  职工姓名：" << this->m_Name
		<< "  岗位：" << this->getDepName()
		<< "  岗位职责：管理公司所有事务。" << endl;
}


//获取岗位名称
string Boss::getDepName() {
	return string("总裁");
}

Boss:: ~Boss() {

}