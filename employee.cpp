#include <iostream>//ע��û��.h,
using namespace std;
#include "work.h"  //ע�������Ų��Ǽ�����
#include "employee.h"
#include<string>//!ע�����治�ܼ�.h�����������ӡ����!

employee::employee(int num, string name, int deptnum)
{
		this->m_num = num;
		this->m_name = name;
		this->m_deptnum = deptnum;
}//���캯��
	 

	 void employee::ShowInfo()
	 {
		 cout<<"���:"<<this->m_num
			 <<"\t������"<< this->m_name
			 <<"\t��λ��"<<this->Getdeptname()
			 <<"\t��λְ����ɾ�����������!"<<endl;
	 }
	 /*void employee::depttask()
	 {
	 }*/
	 string employee::Getdeptname()
	 {
			return "��ͨԱ��";
	 }