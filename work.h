#pragma once //��ֹ�ļ��ظ�����
#include<iostream>//��׼���������
using namespace std;//ʹ�ñ�׼�������ռ䣬��cin<<����Ҫ
#include<string.h>

class work //����ļ�ֻ��Ҫ.h�ļ���Ϊ����ʹ��
{
public:
	virtual void ShowInfo()=0;//��ֻ�и����������0�������麯����
	/*virtual void depttask()=0;*/
	virtual string Getdeptname()=0;//����λ�ķ���ֵ���ַ����ͣ�
//private:����Ϊ���ﵼ�º�����������ã�
	int m_num;
	string m_name;
	int m_deptnum;
};