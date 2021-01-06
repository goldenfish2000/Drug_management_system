#include <iostream>
using namespace std;
int fun_1(int a,int b)//通过返回值将新数传给主函数
{
	int temp_1,temp_2,temp_3,temp_4;
	int d;
	temp_1=a%10;//a个位
	temp_2=a/10;//a十位
	temp_3=b%10;
	temp_4=b/10;
	d=temp_1*1000+temp_3*100+temp_2*10+temp_4;
	return d;
}
int main()
{
	//通过返回值将新数传给主函数
	int figure_1,figure_2;
	int temp;
	cout<<"请输入两个两位数a和b:";
    cin>>figure_1>>figure_2;
	int fun_3(int a,int b);
	temp=fun_1(figure_1,figure_2);
	cout<<"合并后的数为:"<<temp<<endl;
}
