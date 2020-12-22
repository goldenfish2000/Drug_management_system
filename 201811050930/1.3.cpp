#include<iostream>
#include<stdio.h>
using namespace std;
void fun(int *a, int *b,int *c);
int main(void)
{
    int a, b;
    int c;
    cout << "input a and b" << endl;
    cin >> a;
    cin >> b;
    fun(&a, &b, &c);
    cout <<"c is"<< c << endl;
    return 0;
}
void fun(int *a,int *b ,int *c)
{
    int x,y,z,w;
    x = *a / 10;//十位
    y = *a % 10;//千位
    z = *b / 10;//个位
    w = *b % 10;//百位
    *c = x * 10 + y * 1000 + z + w * 100;
}