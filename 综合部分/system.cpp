#include<iostream>
#include<mysql.h>
#include <winsock.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include <ctime>
#include"class.h"

using namespace std;

int main(int argc, char *argv[])
{
	Database drug_management_system;
	Drug drug_1;
    if (mysql_library_init(0, NULL, NULL))
    {
        printf("could not initialize MySQL library\n");
        getchar();
        exit(1);
    }
    mysql_init(&mysql);
    MYSQL *ret = mysql_real_connect(&mysql, "127.0.0.1", "root","201811050930","Drug_management_system",3306, NULL, 0);
	//MYSQL *ret = mysql_real_connect(&conn, "127.0.0.1", "root","201811050930","student",3306, NULL, 0);
	//                                         地址     用户名称    密码      数据库名  不是0，其值将用作TCP/IP连接的端口号
     if (!ret)
    {
        printf("Failed to connect to database:%s\n", mysql_error(&mysql));
        getchar();
        exit(1);
    }
    else {
        printf("success!\n");
    }

	drug_management_system.input_all_data();//建库

	while(1)
	{
		system("cls");
		int operate;
		cout<<"*************************************"<<endl;
		cout<<"*          药品信息管理系统         *"<<endl;
		cout<<"*                                   *"<<endl;
		cout<<"*请选择要进行的操作：               *"<<endl;
		cout<<"*1.查询药品信息                     *"<<endl;
		cout<<"*2.增加药品信息                     *"<<endl;
		cout<<"*3.删除药品信息                     *"<<endl;
		cout<<"*4.修改药品信息                     *"<<endl;
		cout<<"*5.显示所有药品信息                 *"<<endl;
		cout<<"*0.退出                             *"<<endl;
		cout<<"*                                   *"<<endl;
		cout<<"*************************************"<<endl;

		cin>>operate;
		system("cls");
		char y_n;
		switch(operate)
		{
		   case 1:{
			   system("cls");
	           drug_1.print_data();
			   cout<<"是否继续(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 2:{
			   system("cls");
	           drug_1.drug_input_data();
			   cout<<"是否继续(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 3:{
			   system("cls");
			   drug_1.delete_data();
			   cout<<"是否继续(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 4:{
			   system("cls");
			   drug_1.change_data();
			   cout<<"是否继续(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 5:{
			   drug_management_system.print_all_data();
			   cout<<"是否继续(Y/N): "<<endl;
			   cin>>y_n;
			   if(y_n=='Y' || y_n=='y')
				   continue;
			   else 
				   break;
				  };
		   case 0:{
			   mysql_close(&mysql);
			   cout<<"已退出，感谢使用！"<<endl;
				  };	   
		   default :
			   cout<<"输入的指令有误，请重新输入: "<<endl;
		}
	}
    return 0;
}
