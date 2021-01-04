//class.h
#ifndef _CLASS_H
#define _CLASS_H
#include<mysql.h>
#include <winsock.h>
#include <iostream>
using namespace std;

MYSQL mysql,*sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
MYSQL_RES *res;       // 查询结果集，结构类型
MYSQL_FIELD *fd ;     // 包含字段信息的结构
MYSQL_ROW row ;       // 存放一行查询结果的字符串数组

class Database
{
	public :
		void input_all_data()
		{
		   char qbuf[500];
		   sprintf(qbuf, "use drug_management_system;");//将数据库操作指令复制到字符数组中
		   mysql_query(&mysql, qbuf);//对数据库进行操作
		   sprintf(qbuf, "CREATE TABLE drug(drug_id VARCHAR(100) NOT NULL,drug_title NVARCHAR(100) NOT NULL,Manufacturers NVARCHAR(100) NOT NULL,Date_of_production date default NULL,shelf_life INT NOT NULL,purposes NVARCHAR(100) NOT NULL,price INT NOT NULL,num INT NOT NULL,hands_on NVARCHAR(100) NOT NULL,PRIMARY KEY (drug_id));");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('001','essential balm','Tianjin Pharmaceutical Factory','2020-10-18','24','External','14','24','Li ming' );");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('002','Quick','Shanghai Pharmaceutical Factory','2020-10-22','24','Cold medicine','11','10','Wang fei');");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('003','wuji baifeng pills','Beijing Pharmaceutical Factory','2020-9-30','12','Gynaecological drugs','15','23','Wang Wei');");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('004','BABY COLD GRANULES','Beijing Pharmaceutical Factory','2020-10-11','12','Cold medicine','12','30','Wang Yong');");
		   mysql_query(&mysql, qbuf);
		   sprintf(qbuf, "INSERT INTO drug (drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on)VALUES('005','Zinc glucosate oral solution','Harbin Pharmaceutical Factory','2020-10-22','24','Health care medicine','110','8','Li ming');");
		   mysql_query(&mysql, qbuf);
		};
		void print_all_data()
		{
		   char qbuf[500];
		   sprintf(qbuf, "SELECT * FROM drug;");
		   mysql_query(&mysql, qbuf);
		   mysql_query(&mysql, "select * from drug");//储存结果集
		   res=mysql_store_result(&mysql);
		   int n;
		   n=mysql_field_count(&mysql);//获取字段数
		   cout<<"药品编号       药品名称        生产厂家                      生产日期       保质期     用途     价格    数量       经手人"<<endl;
		   while (row = mysql_fetch_row(res))
		   {				  
			for(int i=0;i<n;i++)
				printf("%s     ",row[i]);
				cout<<endl;		
		   };
		}

		void drug_input_data()
		{
			system("cls");
			getchar();//防止读取数据有误
			//添加药品信息
			cout<<"请输入要添加的药品编号"<<endl;
			cin.getline(drug_id,10);
			cout<<"请输入要添加的药品名称"<<endl;
			cin.getline(drug_title,20);
			cout<<"请输入要添加的药品生产厂家"<<endl;
			cin.getline(Manufacturers,100);
			cout<<"请输入要添加的药品生产日期"<<endl;
			cin.getline(Date_of_production,50);
			cout<<"请输入要添加的药品保质期"<<endl;
			cin>>shelf_life;
			getchar();//防止读取数据有误
			cout<<"请输入要添加的药品用途"<<endl;
			cin.getline(purposes,50);
			cout<<"请输入要添加的药品价格"<<endl;
			cin>>price;
			cout<<"请输入要添加的药品数量"<<endl;
			cin>>num;
			getchar();//防止读取数据有误
			cout<<"请输入要添加的药品经手人"<<endl;
			cin.getline(hands_on,30);
			//写入数据库
			sprintf(qbuf, "INSERT INTO drug VALUES('%s','%s','%s','%s','%d','%s','%d','%d','%s');",drug_id,drug_title,Manufacturers,Date_of_production,shelf_life,purposes,price,num,hands_on);
			mysql_query(&mysql, qbuf);
		
		};
		void change_data()
		  {
			  char qbuf[200],id_title[50];
			  char temp[50],temp1[50];
			  int t;
			  cout<<"请输入要修改的药品编号或名称: "<<endl;
			  cin>>id_title;
			  sprintf(qbuf, "select * from  drug where drug_id='%s' or drug_title ='%s';",id_title,id_title);
	          mysql_query(&mysql, qbuf);
			  cout<<"请输入要修改的属性名: "<<endl;
			  cin>>temp;
			  cout<<"请输入要修改的值: "<<endl;
			  if(temp[0]=='s' || (temp[0]=='p' && temp[1]=='r') || temp[0]=='n')//修改元素属性对比
			   {
				   cin>>t;
				   sprintf(qbuf, "UPDATE drug SET %s='%d' where drug_id='%s' or drug_title ='%s';",temp,t,id_title,id_title);
	               mysql_query(&mysql, qbuf);
				   cout<<"修改成功!  "<<endl;
			   }
			   else
			   {
				   cin>>temp1;
				   sprintf(qbuf, "UPDATE drug SET %s='%s' where drug_id=%s or drug_title =%s;",temp,temp1,id_title,id_title);
				   mysql_query(&mysql, qbuf);
				   cout<<"修改成功!  "<<endl;
			   }
		  };
		  void delete_data()
		  {
			  char qbuf[200],id_title[50];
			  cout<<"请输入要删除的药品编号或名称: "<<endl;
			  cin>>id_title;
			  sprintf(qbuf, "delete from  drug where drug_id='%s' or drug_title ='%s';",id_title,id_title);
	          mysql_query(&mysql, qbuf);
		  };
private:
	char drug_id[10],drug_title[20],Manufacturers[100],Date_of_production[50],purposes[50],hands_on[30],qbuf[500];
	int shelf_life,price,num;


};

class Drug :public Database
{
  public:
		void print_data()
		{
		  char qbuf[500],id_title[50];
		  system("cls");
		  cout<<"请输入要查询的药品编号或名称: "<<endl;
		  cin>>id_title;//读取要查询的药品信息关键字
		  sprintf(qbuf, "SELECT * FROM drug where drug_id='%s' or drug_title ='%s';",id_title,id_title);//通过数据库进行查询
		  mysql_query(&mysql, qbuf);
		  mysql_query(&mysql, "select * from drug;");//储存结果集
		  res=mysql_store_result(&mysql);
		  int n;
		  n=mysql_field_count(&mysql);//获取字段数
		  cout<<"药品编号       药品名称        生产厂家                      生产日期       保质期     用途     价格    数量       经手人"<<endl;
		  while (row = mysql_fetch_row(res))
		  {
			for(int i=0;i<n;i++)
			 printf("%s     ",row[i]);
			cout<<endl;
		  }
		};
		    
private:
	char drug_id[10],drug_title[20],Manufacturers[100],Date_of_production[50],purposes[50],hands_on[30],qbuf[500];
	int shelf_life,price,num;

};


#endif