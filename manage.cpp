#include <iostream>//ע��û��.h,
using namespace std;
#include "work.h"  //ע�������Ų��Ǽ�����
#include "manage.h"
#include<string>//!ע�����治�ܼ�.h�����������ӡ����!

manage::manage(int num, string name, int deptnum)
{
		this->m_num = num;
		this->m_name = name;
		this->m_deptnum = deptnum;
}//���캯��
	 

	 void manage::ShowInfo()
	 {
		 cout<<"���:"<<this->m_num
			 <<"\t������"<< this->m_name
			 <<"\t��λ��"<<this->Getdeptname()
			 <<"\t��λְ������ϰ彻��������!"<<endl;
	 }
	 /*void employee::depttask()
	 {
	 }*/
	 string manage::Getdeptname()
	 {
			return "����";
	 }