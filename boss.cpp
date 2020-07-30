#include <iostream>//注意没有.h,
using namespace std;
#include "work.h"  //注意是引号不是尖括号
#include "boss.h"
#include<string>//!注意里面不能加.h，否则下面打印报错！!

boss::boss(int num, string name, int deptnum)
{
		this->m_num = num;
		this->m_name = name;
		this->m_deptnum = deptnum;
}//构造函数
	 

	 void boss::ShowInfo()
	 {
		 cout<<"编号:"<<this->m_num
			 <<"\t姓名："<< this->m_name
			 <<"\t岗位："<<this->Getdeptname()
			 <<"\t岗位职责：统管所有的任务!"<<endl;
	 }
	 /*void employee::depttask()
	 {
	 }*/
	 string boss::Getdeptname()
	 {
			return "老板";
	 }