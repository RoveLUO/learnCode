#include "manager.h"

Manager::Manager(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepID = dID;
}

//��ʾ������Ϣ
void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "  ְ��������" << this->m_Name
		<< "  ��λ��" << this->getDepName()
		<< "  ��λְ������ϰ彻�������񣬲��·������Ա����" << endl;
}


//��ȡ��λ����
string Manager::getDepName() {
	return string("����");
}

Manager:: ~Manager() {

}