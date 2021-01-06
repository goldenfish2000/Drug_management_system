#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int m,n; 
	int i,j;
	int tem1[60];
	int tem2[60];
	cout<<"请输入地图的长和宽";
	cin>>n>>m;
	char s[50][50];//={ "ooooopoooo",
	              // "oxooopoooo",
				 //  "ooooxpoooo",
				 //  "ooooopoooo"};
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cin>>s[i][j];
			//cout<<s[i][j];
		}
		//cout<<endl;
	}
	int c;
	int t=1;
	cout<<"请输入扩散周期";
	cin>>c;
for(int f=0;f<c;f++){
   for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(s[i][j]=='X'){
				tem1[t]=i;
				tem2[t]=j;			
				t++;	
			}	
		}
	}//查找病毒位置坐标
	 //yuanweizhi
	for(t=t-1;t>=1;t--){
		if(s[tem1[t]][tem2[t]+1]!='P'){
	        s[tem1[t]][tem2[t]+1]='X';
	        s[tem1[t]][tem2[t]-1]='X';
		    s[tem1[t]+1][tem2[t]]='X';
	        s[tem1[t]-1][tem2[t]]='X';
	}
	    else
	        s[tem1[t]][tem2[t]-1]='X';
		    s[tem1[t]+1][tem2[t]]='X';
		    s[tem1[t]-1][tem2[t]]='X';
	}//tihuan
}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			cout<<s[i][j];
		}
		cout<<endl;
	}
	return 0;	
 }
