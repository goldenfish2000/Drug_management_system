#include<iostream>
#include<stdio.h>
#include <algorithm>
using namespace std; 
typedef struct STU
{
    int grade;
    int Chinese;
    int math;
    int English;
    int sum;
}student;

bool cmp(struct STU a, struct STU b);
int main(void)
{
    static int n;
    cout << "input the number: " << endl;
    cin >> n;
    struct STU all[1000];
    for (int i = 0; i < n;i++)
    {
        all[i].grade = i + 1;
        cin >> all[i].Chinese >> all[i].math >> all[i].English;
        all[i].sum = all[i].Chinese + all[i].math + all[i].English;
    } 
    //Sort(start,end,cmp)
    //start表示要排序数组的起始地址；
    //end表示数组结束地址的下一位；
    //cmp用于规定排序的方法，可不填，默认升序。
    sort(all, all+n, cmp);//sort函数用于C++中，对给定区间所有元素进行排序，默认为升序，也可进行降序排序。
	for(int i = 0; i < 5; ++i) 
    {
        cout << all[i].grade <<" "<< all[i].sum << endl;
    }
}
//比较函数cmp(),告诉程序要实现从大到小的排序的方法
bool cmp(struct STU a, struct STU b) 
{
	if(a.sum != b.sum) 
    {
		return a.sum > b.sum;  //总分不同
	} 
    else
    {
		if(a.Chinese != b.Chinese) 
        {
			return a.Chinese > b.Chinese; //语文不同
		} 
        else 
        {
			return a.grade < b.grade;   //后者语文高，排位做反
		}
	}
}