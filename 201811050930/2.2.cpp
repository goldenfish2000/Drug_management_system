#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std; 
typedef struct monkey {
    int num;
    struct monkey * next;
} monkey_t;
//head指向第一个节点，tail指向最后一个节点
monkey_t *head = NULL, *tail = NULL;
 
void create(int nn) //猴子的个数
{   
    monkey_t *p = NULL, *q = NULL;  //p指向一个新分配的节点，q指向当前最后一个节点
 
    p = (monkey_t *)malloc(sizeof (monkey_t));//创立头节点
    p->num = 1;
    p->next = NULL;
    head = p;
    q = p;
    for (int i = 2; i <= nn; i++) {
        p = (monkey_t *)malloc(sizeof (monkey_t));
        p->num = i;
        p->next = NULL;
        q->next = p;
        q = p;
    }
    tail = q;
    tail->next = head;  //形成闭环
}
 
int select(int mm) 
{
    int x = 0, res;
    monkey_t *p = NULL, *q = NULL;  //p指向当前要判断的节点，q跟随在p的后面，比p慢一拍
 
    q = tail;
    do {
        p = q->next;    //定位p
        x++;
        if (x % mm == 0) 
        {
            q->next = p->next;   //链接前后节点
            free(p);   //删掉指到的结点
        } 
        else 
        {
            q = p;  //q跟进一步
        }
    } while (q != q->next); //循环直到只剩下一个节点
    res = q->num;
    free(q);
    return res;
}
 
int main() 
{
    int n, m;

    cout << "Please input the number of monkey." << endl;
    cin >> n;
    cout << "Please input the number of interval m." << endl;
    cin >> m;

    create(n);
    int king = select(m);
    cout << "monkey king is No. " << king << endl;
    return 0;
}

