#include <iostream>//注意没有.h,
using namespace std;
#include <string.h>
#include "workmanage.h"
#include "employee.h"
#include "boss.h"
#include "manage.h"
#include "work.h"

int main()
{
	//work *abc=new boss(1, "张三",2);//!字符串记得加上引号!

	//abc->ShowInfo();

	//delete abc;


	int choice=0;
	while(true)
	{
		workManage a; //这个一般放在循环外面
		a.Show_Menu();

		cout<<"请输入您的选择：";
		cin>>choice;

		switch(choice) //switch 函数记得下面加括号！！！！
		{
			case 0://退出系统
				a.Exit();
				//return 0;
				break;
			case 1://增加职工
				a.AddEmp();
				break;
			case 2://显示职工
				a.show_Emp();
				break;
			case 3://删除职工
				a.Del_Emp();
				break;
			case 4://修改职工
				a.Mod_Emp();
				break;
			case 5://查找职工
				a.Find_Emp();
				break;
			case 6://职工排序
				a.sort_Emp();
				break;
			case 7://清空文档
				a.cle_Emp();
				break;
			default:
				{
					cout<<"输入错误，请重新输入"<<endl;
				system("pause");
				system("cls");//输入其他的清空屏幕
				break;
				}
		}
				
	}
	

	system("pause");
	return 0;

}
