#include <iostream>//ע��û��.h,
using namespace std;
#include "work.h"  //ע�������Ų��Ǽ�����
#include "boss.h"
#include<string>//!ע�����治�ܼ�.h�����������ӡ����!

boss::boss(int num, string name, int deptnum)
{
		this->m_num = num;
		this->m_name = name;
		this->m_deptnum = deptnum;
}//���캯��
	 

	 void boss::ShowInfo()
	 {
		 cout<<"���:"<<this->m_num
			 <<"\t������"<< this->m_name
			 <<"\t��λ��"<<this->Getdeptname()
			 <<"\t��λְ��ͳ�����е�����!"<<endl;
	 }
	 /*void employee::depttask()
	 {
	 }*/
	 string boss::Getdeptname()
	 {
			return "�ϰ�";
	 }