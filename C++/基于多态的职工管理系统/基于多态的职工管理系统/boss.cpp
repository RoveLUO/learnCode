#include "boss.h"

Boss::Boss(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepID = dID;
}

//��ʾ������Ϣ
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "  ְ��������" << this->m_Name
		<< "  ��λ��" << this->getDepName()
		<< "  ��λְ�𣺹���˾��������" << endl;
}


//��ȡ��λ����
string Boss::getDepName() {
	return string("�ܲ�");
}

Boss:: ~Boss() {

}