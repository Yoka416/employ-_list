#pragma once //��ֹ�ļ��ظ�����
#include<iostream>//��׼���������
using namespace std;//ʹ�ñ�׼�������ռ䣬��cin<<����Ҫ
#include<string.h>
#include "work.h" //!ÿһ������ǵù�������ͷ�ļ�!

class boss :public work //!ÿһ������ǵù������ຯ��!
{	
public:
	boss(int num, string name,int deptnum);//���캯��Ҳ��Ҫ����Ȩ����

	//��ʾ������Ϣ
	virtual void ShowInfo();
	/*virtual void depttask()=0;*/

	//��ȡ��λ����
	virtual string Getdeptname();
};//!ͷ�ļ��е���һ��Ҫ�ǵ��������Ϸֺ�!