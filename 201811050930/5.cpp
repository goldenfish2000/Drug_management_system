#include<bits/stdc++.h>
using namespace std;
char flag2[8]={'+','-','*','/','^','=','(',')'} ;
char com1[9][9]={'?','+','-','*','/','(',')','=','^','+','>','>','<','<','<','>','>','<','-','>','>','<','<','<','>','>','<','*','>','>','>','>','<','>','>','<','/','>','>','>','>','<','>','>','<','(','<','<','<','<','<','~','?','<',')','>','>','>','>','?','>','>','>','=','<','<','<','<','<','?','~','<','^','>','>','>','>','<','>','>','>'};
//创建运算符优先级表
//     + - * /  ( ) =
// +   > > < <  < > >
// -   > > < >  < > >
// *   > > > >  < > >
// /   > > > >  < > >
// (   < < < <  < ~ 
//	)  > > > >    > >
// =   < < < <  <   ~
int compareflag(char c)//查看c是不是运算符 
{
	for(int i=0;i<8;i++)
	{
		if(c==flag2[i])
		return 1;
	}
	return 0;
}

int com(char a1,char a2)//用于比较两个计算符的优先级，a                                                1是flag栈顶的符号，a2是待比较的符号 
{
	int i, j;
	for(i=0;i<9;i++)
	{
		if(com1[i][0]==a1)
		break;
	}
	for(j=0;j<9;j++)
	{
		if(com1[0][j]==a2)
		break;
	}
	if(com1[i][j]=='>')
	return 1;//待比较的运算符优先级小，须开始运算
	else if(com1[i][j]=='~')
	return 2;//待比较的运算符优先级相同，一起删去
	else if(com1[i][j]=='<')
	return 3;//待比较的运算符优先级大，须存入栈中
	else if(com1[i][j]=='?')
	return 0;//输入的运算式有误 
}
int main()
{
	stack<int> number;//存数字的栈 
	stack<char> flag;//存运算符的栈 
	flag.push('=');//先在运算符栈里存储一个=用于比较 
	char c1;//一个一个输 
	char total[20]={'\0'};//存储完整的数字字符串 
	int data;//存要压入栈的数
	cout<<"please input expresssion,end with '=' ";
	c1=getchar();
	char word[2];
	while(c1!='='||flag.top()!='=')
	{
		if(c1>='0'&&c1<='9')
		{
			word[0]=c1;
			word[1]='\0';
			strcat(total,word);
			c1=getchar();
			if(compareflag(c1))
			{
				data=(int)atoi(total);
				number.push(data);
				strcpy(total,"\0");
			}
		} 
		else if(compareflag(c1))
		{
			char flag1=flag.top();			
			int flagcom=com(flag1,c1);
			if (flagcom==1)
			{
				flag.pop();
				int a1,a2;
				a1=number.top();
				number.pop();
				a2=number.top();
				number.pop();
				switch(flag1)
				{
					case '+':
						number.push(a1+a2);break;
					case '-':
						number.push(a1-a2);break;
					case '*':
						number.push(a1*a2);break;
					case '/':
						number.push(a1/a2);break;
					case '^':
						number.push(pow(a1,a2));break;					
				}
			} 
			else if(flagcom==2)
			{
				c1=getchar();
				flag.pop();
			}
			else if(flagcom==3)
			{
				flag.push(c1);
				c1=getchar();
			}
			else if(flagcom==0)
			{
				cout<<"please input the right expression !"<<endl; 
			}
		}
	}	
	cout<<"result: "<<number.top()<<endl<<endl; 
	getchar();
	return 0;
}
