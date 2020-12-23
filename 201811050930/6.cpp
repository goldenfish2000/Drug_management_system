
#include<string>
#include<cstring>
#include <iostream>
using namespace std;
class Vehicle
{
    public :
        void input_data()
        {
            cout << "input the wheels:" << endl;
            cin >> wheels;
            cout << "input the weihgt:" << endl;
            cin >> weight;
        }
        ~Vehicle();
        void show()
        {
            {
                cout <<"wheels: "<< wheels << endl;
                cout<<"weight: " << weight << endl;
            }
        }

    protected:
        int wheels;
        int weight;
};
class Car :private Vehicle
{
    private:
	int passenger_load;

    public:
    void input()
	{ 
        cout<<"This car: "; 
        Vehicle::input_data();
        cout<<"passenger load: "; 
        cin>>passenger_load;
    }	
    void show()
    {
        Vehicle::show();
        cout<<" passenger_load: "<<passenger_load<<endl;
    }
};
class Truck :private Vehicle
{
    private:
	int passenger_load;
    float payload;

    public:
    void input()
	{ 
        cout<<"This truck: "; 
        Vehicle::input_data();
        cout<<"passenger load: "; 
        cin>>passenger_load;
        cout<<"payload : "; 
        cin>>payload;
    }	
    void show()
    {
        Vehicle::show();
        cout<<" passenger load: "<<passenger_load<<endl;
        cout<<" payload: "<<payload<<endl;
    }
};