#include<iostream>
#include<stdio.h>
using namespace std;
void fun(int &m,int &n);
int main(void)
{
    int a[1000];
    int m,n,number,c,t;
    fun(m, n);
    number = m;
    c = 1;     //当前数
    t = 0;     //数组下标
    for (int i = 0; i < m; i++)
        a[i] = i + 1;
    while(number>1)
    {
       if(a[t]>0)
		{
			if(c!=n)        //没数到第n个时
			{
                c++;             //向下一个数
                t = (t + 1) % m; //实现数组下标加1,保证是绕环进行数
            }
			else
			{
                a[t] = 0;  //数组清零
                c = 1;     //从头数
                number--;  //总数减一
                t = (t + 1) % m;  //实现数组下标加1,保证是绕环进行数
            }
		}
		else
		{
            t = (t + 1) % m;   //实现数组下标加1,保证是绕环进行数
        }
	}
    for (int i = 0; i < m; i++)
    {
		if(a[i]>0)
            cout << "monkey king: " << a[i] << endl;
    }
    return 0;
}
void fun(int &m,int &n)
{
    cout << "how many monkeys?" << endl;
    cin >> m;
    cout << "input the n:" << endl;
    cin >> n;
}
