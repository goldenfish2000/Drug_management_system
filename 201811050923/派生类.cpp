#include<iostream>
using namespace std;
class vehicle
{
protected:
int wheels;
int weight;
public:
vehicle(int x, int y)
{
wheels = x;
weight = y;
}
void show()
{
cout <<"wheels="<<wheels<<endl<<"weight="<<weight<<endl;
}
};
class car:private vehicle
{
protected:
    int passenger_load;
public:
car(int x, int y, int z) :vehicle(x,y)
{
passenger_load = z;
}
void show()
{
vehicle::show();
cout << "passenger_load=" << passenger_load << endl;
}
};
class truck :private vehicle
{
	protected:
    int passenger_load;
    int payload;
public:
truck(int x, int y, int z,int m) :vehicle(x, y)
{
passenger_load = z;
payload = m;
}
void show()
{
vehicle::show();
cout << "passenger_load=" << passenger_load <<endl<< "payload=" << payload << endl;
}
};
int main()
{
	int w,ww,p,pp; 
	cout<<"请分别输入车轮数、车身重量、载人数、载重量"<<endl;
	cin>>w>>ww>>p>>pp;
    truck T(w, ww, p, pp);
    T.show();
    return 0;
}
