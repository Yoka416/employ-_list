#pragma once //防止文件重复包含
#include<iostream>//标准输入输出流
using namespace std;//使用标准的命名空间，用cin<<等需要
#include "employee.h"
#include "boss.h"
#include "manage.h"
#include<fstream>
#define FILENAME "empoly.txt"
//#include<string.h>


class workManage  //这个类用于把控全局框架！
{
public:
	//构造函数
	workManage();

	//展示菜单
	void Show_Menu();//为了这个菜单功能专门开辟了一组文件
	void Exit();
	void AddEmp();//添加员工第一步
	void save();//保存到文件
	int get_EmpNum();//获取员工个数
	void  init_Emp();//初始化
	void show_Emp();

	int Is_exist(int id);//判断职工是否存在
	void Del_Emp();//用于删除职工
	void Mod_Emp();//用于修改职工
	void Find_Emp();//查找职工
    void sort_Emp();//职工编号排序
	void cle_Emp();
	//int repeatnum(int num);


	bool FileEmpty;
	int m_EmpNum;//记录员工个数
	work **m_EmpArray;//!注意是双*!用来指向新开辟的数组空间
	
	//析构函数
	~workManage();
	
};