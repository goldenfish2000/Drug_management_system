#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
    char map[100][100];
    int term,x[100][100]={0};
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M;i++)
        for (int j = 0; j < N;j++)
         {
             cin >> map[i][j];
             if(map[i][j]=='X')
             {
                 x[i][j] = 1;
             }else if(map[i][j]=='P')
             {
                 x[i][j] = 2;
             }
         }
    cin >> term;
    while (term>0)
    {
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (x[i][j] != 2 && x[i][j] == 1)
                {
                    if(x[i+1][j]!=2)
                    map[i+1][j] = 'X';
                    if(x[i-1][j]!=2)
                    map[i-1][j] = 'X';
                    if(x[i][j+1]!=2)
                    map[i][j+1] = 'X';
                    if(x[i][j-1]!=2)
                    map[i][j-1] = 'X';
                }
            } 
        }
        for (int i = 0; i < M;i++)
        {
            for (int j = 0; j < N;j++)
           {
             if(map[i][j]=='X')
             {
                 x[i][j] = 1;
             }else if(map[i][j]=='P')
             {
                 x[i][j] = 2;
             }
            }
        }
        term--;
    }  
        for (int i = 0; i < M;i++)
        {
            for (int j = 0; j < N;j++)
            cout << map[i][j];
            cout << endl;
        }
        cout << endl;
        return 0;
}
