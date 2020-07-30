#include "workmanage.h"
#include "work.h" 
#include<string>



//构造函数
	workManage::workManage()//切记在.cpp文件函数前加上类名
	{
		ifstream ifs;
		ifs.open(FILENAME,ios::in);
		if(!ifs.is_open())
		{
			cout<<"文件不存在！"<<endl;
			//对头文件中的两个变量进行初始化
			//添加员工第二步
			this->m_EmpNum =0;
			this->m_EmpArray=NULL;
			this->FileEmpty=true;
			ifs.close();
			return;
		}

		char ch;
		ifs>>ch;
		if(ifs.eof())
		{
			cout<<"文件为空！"<<endl;
			//对头文件中的两个变量进行初始化
			//添加员工第二步
			this->m_EmpNum =0;
			this->m_EmpArray=NULL;
			this->FileEmpty=true;
			ifs.close();
			return;
		}

		

		int num= this->get_EmpNum();
		cout<<"文件中的职工的数量为："<<num<<endl;
		this->m_EmpNum = num;//更新成员属性
		this->FileEmpty=false;

		//创建堆区数组
		this->m_EmpArray= new work*[this->m_EmpNum];

		//初始化
		init_Emp();

		//测试代码
		//for(int i=0;i<this->m_EmpNum;i++)
		//{
		//	cout<<"职工编号："<<this->m_EmpArray[i]->m_num<<" "   //!这里一定要加空格，不然会把两个输入读成一个!
		//		<<"职工姓名："<<this->m_EmpArray[i]->m_name<<" "   
		//		<<"部门职位："<<this->m_EmpArray[i]->Getdeptname()<<endl;
		//}


	}
	
	//析构函数
	workManage::~workManage()
	{
		if(this->m_EmpArray!=NULL)
		{
			delete[] this->m_EmpArray;
			this->m_EmpArray=NULL;
		}
		  
	}

void workManage::Show_Menu()
{
	cout<<"******************************"<<endl;
	cout<<"*****欢迎使用职工管理系统*****"<<endl;
	cout<<"********0.退出管理程序********"<<endl;
	cout<<"********1.增加职工信息********"<<endl;
	cout<<"********2.显示职工信息********"<<endl;
	cout<<"********3.删除离职职工********"<<endl;
	cout<<"********4.修改职工信息********"<<endl;
	cout<<"********5.查找职工信息********"<<endl;
	cout<<"********6.按照编号排序********"<<endl;
	cout<<"********7.清空所有文档********"<<endl;
	cout<<"******************************"<<endl;

}

void workManage::Exit()
{
	 cout<<"欢迎下次光临！"<<endl;
	 system("pause");
	 //return 0;想要用return需要加到switch那里效果是相同的
	 exit(0);//系统的退出函数
}

//int workManage::repeatnum(int num)
//{
//	for(int a=0; a<this->m_EmpNum;a++)
//		{
//			if(num=this->m_EmpArray[a]->m_num)
//			{
//				return -1;
//			}
//		}
//}

void workManage::AddEmp()//！类函数一定要在前面加上类名！
{
	cout<<"请输入需要添加的职工人数："<<endl;
	int AddNum=0;
	cin>>AddNum;//!箭头不要写反!
	if(AddNum>0)
	{
		int Emp= this->m_EmpNum+AddNum;//此时员工总人数

		//开辟新的空间数组指针
		work **newspace= new work*[Emp];//!注意✳是在数组前面!

		if(this->m_EmpNum!=NULL)
		{
			for(int i=0;i<this->m_EmpNum;i++)
		{
			newspace[i]=this->m_EmpArray[i];//把旧空间的数传给新开辟的空间
		}
		}
		int i;
		for(i=0;i<AddNum;i++)
	{
		
			 cout<<"请输入第"<<i+1<<"名职工的编号："<<endl;//!出现数字时考虑单独放!
			int num;
			cin>>num;
			/*int ret=this->repeatnum(b);
			if(ret!=-1)
			{
				break;
			}
			cout<<"输入编号重复，请重新输入！"<<endl;*/
		 


		cout<<"请输入第"<<i+1<<"名职工的姓名："<<endl;
		string name;
		cin>>name;

		cout<<"请输入第"<<i+1<<"名职工的职位："<<endl;
		cout<<"1、员工"<<endl;
		cout<<"2、经理"<<endl;
		cout<<"3、老板"<<endl;
		int deptnum;
		cin>>deptnum;

		work* worker=NULL;

		switch(deptnum)//这种写法仅仅是根据最后一个岗位信息来添加数据
		{
		case 1:
			worker = new employee(num,name,1); //!记得调用头文件
			break;
		case 2:
			worker = new manage(num,name,2); 
			break;
		case 3:
			worker = new boss(num,name,3); 
			break;
		default:
			break; //!default一定要有!
		}
		newspace[i+this->m_EmpNum]=worker;//！右边不一定非要是数组！
		
	}
		//释放原有空间
		delete[] this->m_EmpArray;//!!

		//更新空间的指向,让数组指针指向最新开辟的堆区空间
		this->m_EmpArray=newspace;//！这里不用加*！

		//更新新的员工个数
		this->m_EmpNum=Emp;

		//提示信息
		cout<<"成功添加"<<AddNum<<"名职工!"<<endl;
		this->FileEmpty=false;
		this->save();

	}else
	{
		cout<<"输入错误，请重新输入！"<<endl;
	}

system("pause");
system("cls");
}

void workManage:: save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for(int i=0;i<this->m_EmpNum;i++)
	{
		ofs<<this->m_EmpArray[i]->m_num<<" " //!这里一定要加空格，不然会把两个输入读成一个，导致统计人数出错!
			<<this->m_EmpArray[i]->m_name<<" "  
			<<this->m_EmpArray[i]->m_deptnum<<endl;//数组指针后面不是.是->
	}

	ofs.close();//!记得加上括号!
}

int workManage::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int id;
	string name;
	int deptname;

	int num=0;

	while(ifs>>id && ifs>>name && ifs>>deptname)//!ifs>>id代表读id,一个个读，读完之后会返回一个假!
	{
		num=num+1;
	}
	ifs.close();//!添加文件后最后一定要关闭!
	return num;
}

void  workManage::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME,ios::in);

	int Id;
	string name;
	int Did;
	
	int Index=0;
	while(ifs>>Id  && ifs>>name && ifs>>Did)
	{
		work *work= NULL;
		if(Did==1)//！因为没有双等于导致不论怎么输出都是普通员工！
		{
			work=new employee(Id,name,Did);
		}else if(Did==2)
		{
			work=new manage(Id,name,Did);
		}else
		{
			work=new boss(Id,name,Did);
		}
		this->m_EmpArray[Index] = work; 
		Index++;
	}




}
void  workManage:: show_Emp()

{
	if(this->FileEmpty)//!显示函数记得用if进行选择!
	{
		cout<<"该文件不存在或者为空！"<<endl;
	}
	else
	{
		for(int i=0;i<this->m_EmpNum;i++)
		{
			this->m_EmpArray[i]->ShowInfo();//!这个函数可比下面这种方法简捷多了!
			
			//cout<<"职工编号："<<this->m_EmpArray[i]->m_num<<" "   //!这里一定要加空格，不然会把两个输入读成一个!
			//	<<"职工姓名："<<this->m_EmpArray[i]->m_name<<" "   
			//	<<"部门职位："<<this->m_EmpArray[i]->Getdeptname()<<endl;
		}
	}
	
	system("pause");
	system("cls");

}

int workManage::Is_exist(int id)
{
	int index=-1;
	for(int i=0;i<this->m_EmpNum;i++)
	{
		if(this->m_EmpArray[i]->m_num == id)
		{
			index=i;
			//cout<<"该文件存在！"<<endl;
			break;
		}
		/*else
		{
			cout<<"该文件不存在！"<<endl;
		}
			return ret;*/
	}
	return index;//!这个返回刚开始放到for循环里面导致持续出错!

}

void workManage::Del_Emp()
{
	if(this->FileEmpty)
	{
		cout<<"文件为空或不存在！"<<endl;
	}
	else
	{
		cout<<"请输入要删除的员工编号：";
		int id=0;
		cin>>id;
		int index =this->Is_exist(id);//！这里忘了加this！
		if(index!=-1)
		{
			for(int i=index;i<this->m_EmpNum-1;i++)
			{
				this->m_EmpArray[i]=this->m_EmpArray[i+1];
			}
				this->m_EmpNum--;
				this->save();//!忘了同步到文件中！
				cout<<"删除文件成功！"<<endl;//!上述三行代码放错位置了!
		}
		else
		{
				cout<<"找不到该职工，删除文件失败！"<<endl;
		}
	}
		system("pause");
		system("cls");//！这两个只要在主函数中调用就得加，加的的位置都在最后，代表这轮的结束！！
}

void workManage::Mod_Emp()
{
	if(this->FileEmpty)
	{
		cout<<"文件为空或不存在！"<<endl;
	} 
	else
	{
		cout<<"请输入需要修改的职工编号："<<endl;
		int num;
		cin>>num;

		int index = this->Is_exist(num);
		
		if(index!= -1)
		{
			delete this->m_EmpArray[index];
			int newid=0;
			string newname;//！这里初始值为空的时候系统会发生冲突！
			int newdid=0;

			cout<<"已查到第"<<num<<"号职工，请输入新的职工编号："<<endl;
			cin>>newid;
			cout<<"请输入新的职工姓名："<<endl;
			cin>>newname;
			cout<<"请输入新的职工岗位："<<endl;
			cout<<"1、员工"<<endl;
			cout<<"2、经理"<<endl;
			cout<<"3、老板"<<endl;
			cin>>newdid;

			work *work=NULL;
		switch(newdid)
			{
			case 1:
				work=new employee(newid,newname,newdid);
				break;
			case 2:
				work=new manage(newid,newname,newdid);
				break;
			case 3:
				work=new boss(newid,newname,newdid);
				break;
			default:
				break;
			}
		this->m_EmpArray[index]=work;
		cout<<"修改成功！"<<this->m_EmpArray[index]->m_deptnum<<endl;
		this->save();
		
	    }
		else
		{
			cout<<"修改失败，无法找到此人！"<<endl;
		}
	}
	system("pause");
	system("cls");
}

void workManage::Find_Emp()
{
	if(this->FileEmpty)
	{
		cout<<"文件为空或不存在！"<<endl;
	} 
	else
	{
		cout<<"请输入你的查找方式："<<endl;
		cout<<"1、按照编号查找"<<endl;
		cout<<"2、按照姓名查找"<<endl;
		int Select;
		cin>>Select;
		if(Select==1)
		{
			cout<<"请输入查找职工的编号："<<endl;
			int id;
			cin>>id;
			int ret = this->Is_exist(id);

			if(ret!=-1)
			{
				cout<<"查找成功，该职工的信息如下："<<endl;
				this->m_EmpArray[ret]->ShowInfo();
				//flag=true;
			}
			else
			{
				cout<<"查找失败！不存在该职工信息！"<<endl;
			}
		}
		else if(Select==2)
		{
			cout<<"请输入查找职工的姓名："<<endl;
			string name;
			cin>>name;
		
			bool flag=false;

			for(int i=0;i<this->m_EmpNum;i++)
			{
				if(this->m_EmpArray[i]->m_name==name)
				{
					cout<<"查找成功，职工编号"<<this->m_EmpArray[i]->m_num<<"的个人信息如下："<<endl;
					this->m_EmpArray[i]->ShowInfo();
					flag=true;
				}
			}
			if(flag=false)
			{
				cout<<"查找失败！不存在该职工信息！"<<endl;
			}
	}
	else
	{
		cout<<"输入错误，请重新输入！"<<endl;
	}

	}
	system("pause");
	system("cls");
}

void workManage::sort_Emp()
{
	if(this->FileEmpty)
	{
		cout<<"文件为空或不存在！"<<endl;
		system("pause");
		system("cls");
	} 
	else
	{
		cout<<"请选择排序方式："<<endl;
		cout<<"1、按照升序排序"<<endl;
		cout<<"2、按照降序排序"<<endl;
		int select=0;
		cin>>select;

		
			for(int i=0;i<this->m_EmpNum;i++)
			{
				int minormax=i;
				for(int j=i+1;j<this->m_EmpNum;j++)//!这里把j写成i导致文件出错!
				{
					if(select==1)//升序
					{
						if(this->m_EmpArray[minormax]->m_num  >  this->m_EmpArray[j]->m_num)
					  {
						minormax=j;
					  }
					}
					else//降序
					{
						if(this->m_EmpArray[minormax]->m_num  <  this->m_EmpArray[j]->m_num)
					  {
						minormax=j;
					  }
					}
				}
			
		
				if(i!=minormax)
				{
					work *temp =this->m_EmpArray[i];
					this->m_EmpArray[i]=this->m_EmpArray[minormax];
					this->m_EmpArray[minormax]=temp;
				}
			}
		
			cout<<"排序成功，排序结果为："<<endl;
			this->save();
			this->show_Emp();
			
	}

	/*system("pause");
	system("cls");*///因为show_Emp函数中已经存在！！
}

void workManage::cle_Emp()
{
	cout<<"确定要清空么？"<<endl;
	cout<<"1、确定"<<endl;
	cout<<"2、返回"<<endl;
	int select;
	cin>>select;

	
		if(select==1)
	{
		ofstream ofs;
	ofs.open(FILENAME,ios::trunc);//删除现有的文件，并建立空白文件,对程序框无影响

	if(this->FileEmpty)
	{
		cout<<"文件为空或不存在！"<<endl;
	} 
	else//!每次都要提前判断文件是否为空!
	 {
		for(int i=0;i<this->m_EmpNum;i++)
		{
			delete this->m_EmpArray[i];
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray=NULL;//！释放数组后为了防止其成为野指针！

		this->m_EmpNum=0;
		this->FileEmpty=true;
		cout<<"清空文件成功！"<<endl;
	 }
	}

	system("pause");
	system("cls");

}