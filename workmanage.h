#pragma once //��ֹ�ļ��ظ�����
#include<iostream>//��׼���������
using namespace std;//ʹ�ñ�׼�������ռ䣬��cin<<����Ҫ
#include "employee.h"
#include "boss.h"
#include "manage.h"
#include<fstream>
#define FILENAME "empoly.txt"
//#include<string.h>


class workManage  //��������ڰѿ�ȫ�ֿ�ܣ�
{
public:
	//���캯��
	workManage();

	//չʾ�˵�
	void Show_Menu();//Ϊ������˵�����ר�ſ�����һ���ļ�
	void Exit();
	void AddEmp();//���Ա����һ��
	void save();//���浽�ļ�
	int get_EmpNum();//��ȡԱ������
	void  init_Emp();//��ʼ��
	void show_Emp();

	int Is_exist(int id);//�ж�ְ���Ƿ����
	void Del_Emp();//����ɾ��ְ��
	void Mod_Emp();//�����޸�ְ��
	void Find_Emp();//����ְ��
    void sort_Emp();//ְ���������
	void cle_Emp();
	//int repeatnum(int num);


	bool FileEmpty;
	int m_EmpNum;//��¼Ա������
	work **m_EmpArray;//!ע����˫*!����ָ���¿��ٵ�����ռ�
	
	//��������
	~workManage();
	
};