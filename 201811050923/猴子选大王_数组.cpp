#include <iostream>
using namespace std;
int main()
{
    int N,M,i;
    cin>>N>>M;
    int a[N+1000];
    int count=0,number=N;
    for (i=0;i<N;i++)     //1
        a[i]=i+1;
    while(number>1)  //2
    {
        for(i=0;i<N;i++)
        {
            if (!a[i]) //3
            continue; 
            count++;  //4
            if (count==M) //5
            {
                a[i]=0;
                count=0;
                number--;
            }
        }
    }
    for (i=0;i<N;i++) //6
        {
            if (a[i]!= 0)
           cout<<a[i]<<endl;
        }
    return 0;
}
