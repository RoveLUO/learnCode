#include "manager.h"

Manager::Manager(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepID = dID;
}

//显示个人信息
void Manager::showInfo() {
	cout << "职工编号：" << this->m_ID
		<< "  职工姓名：" << this->m_Name
		<< "  岗位：" << this->getDepName()
		<< "  岗位职责：完成老板交给的任务，并下发任务给员工。" << endl;
}


//获取岗位名称
string Manager::getDepName() {
	return string("经理");
}

Manager:: ~Manager() {

}