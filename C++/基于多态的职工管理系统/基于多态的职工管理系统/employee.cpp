#include "employee.h"

Employee :: Employee(int id, string name, int dID) {
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepID = dID;
}

//��ʾ������Ϣ
void Employee :: showInfo() {
	cout << "ְ����ţ�" << this->m_ID
		<< "  ְ��������" << this->m_Name
		<< "  ��λ��" << this->getDepName()
		<< "  ��λְ����ɾ�����������" << endl;
}


//��ȡ��λ����
string Employee ::getDepName() {
	return string("Ա��");
}

Employee:: ~Employee() {

}