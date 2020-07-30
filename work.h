#pragma once //防止文件重复包含
#include<iostream>//标准输入输出流
using namespace std;//使用标准的命名空间，用cin<<等需要
#include<string.h>

class work //这个文件只需要.h文件作为父类使用
{
public:
	virtual void ShowInfo()=0;//！只有父类这里等于0，代表纯虚函数！
	/*virtual void depttask()=0;*/
	virtual string Getdeptname()=0;//！岗位的返回值是字符串型！
//private:！因为这里导致后面变量不能用！
	int m_num;
	string m_name;
	int m_deptnum;
};