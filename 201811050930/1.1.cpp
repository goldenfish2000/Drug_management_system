#include<iostream>
#include<stdio.h>
using namespace std;
int fun(int a, int b, int c, int d);
int main(void)
{
    int a, b;
    int x,y,z,w;
    cout << "input a and b" << endl;
    cin >> a;
    cin >> b;
    x = a / 10;//十位
    y = a % 10;//千位
    z = b / 10;//个位
    w = b % 10;//百位
    cout <<"c is"<< fun(x, y, z, w) << endl;
    return 0;
}
int fun(int a,int b ,int c,int d)
{
    int count;
    count = a * 10 + b * 1000 + c + d * 100;
    return count;
}