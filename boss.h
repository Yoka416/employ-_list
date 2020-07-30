#pragma once //防止文件重复包含
#include<iostream>//标准输入输出流
using namespace std;//使用标准的命名空间，用cin<<等需要
#include<string.h>
#include "work.h" //!每一个子类记得关联父类头文件!

class boss :public work //!每一个子类记得关联父类函数!
{	
public:
	boss(int num, string name,int deptnum);//构造函数也需要放在权限内

	//显示个人信息
	virtual void ShowInfo();
	/*virtual void depttask()=0;*/

	//获取岗位名称
	virtual string Getdeptname();
};//!头文件中的类一定要记得在最后加上分号!