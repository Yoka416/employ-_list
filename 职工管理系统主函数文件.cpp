#include <iostream>//ע��û��.h,
using namespace std;
#include <string.h>
#include "workmanage.h"
#include "employee.h"
#include "boss.h"
#include "manage.h"
#include "work.h"

int main()
{
	//work *abc=new boss(1, "����",2);//!�ַ����ǵü�������!

	//abc->ShowInfo();

	//delete abc;


	int choice=0;
	while(true)
	{
		workManage a; //���һ�����ѭ������
		a.Show_Menu();

		cout<<"����������ѡ��";
		cin>>choice;

		switch(choice) //switch �����ǵ���������ţ�������
		{
			case 0://�˳�ϵͳ
				a.Exit();
				//return 0;
				break;
			case 1://����ְ��
				a.AddEmp();
				break;
			case 2://��ʾְ��
				a.show_Emp();
				break;
			case 3://ɾ��ְ��
				a.Del_Emp();
				break;
			case 4://�޸�ְ��
				a.Mod_Emp();
				break;
			case 5://����ְ��
				a.Find_Emp();
				break;
			case 6://ְ������
				a.sort_Emp();
				break;
			case 7://����ĵ�
				a.cle_Emp();
				break;
			default:
				{
					cout<<"�����������������"<<endl;
				system("pause");
				system("cls");//���������������Ļ
				break;
				}
		}
				
	}
	

	system("pause");
	return 0;

}
