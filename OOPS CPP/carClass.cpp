#include<iostream>
using namespace std;

class Car{
public:
    string name;
    int price;
    int seats;
    string type;
};

void print(Car c){
    cout<<c.name<<" "<<c.price<<" "<<c.seats<<" "<<c.type<<endl;
}

int main(){

    Car c1;
    c1.name = "Honda City";
    c1.price = 1500000;
    c1.seats = 5;
    c1.type = "Sedan";

    Car c2;
    c2.name = "Maruti Swift";
    c2.price = 700000;
    c2.seats = 5;
    c2.type = "Hatchback";

    Car c3;
    c3.name = "Toyota Fortuner";
    c3.price = 4000000;
    c3.seats = 8;
    c3.type = "SUV";
    print(c1);
    print(c2);
    print(c3);
    // cout<<c1.name<<" "<<c1.price<<" "<<c1.seats<<" "<<c1.type<<endl;
    // cout<<c2.name<<" "<<c2.price<<" "<<c2.seats<<" "<<c2.type<<endl;
    // cout<<c3.name<<" "<<c3.price<<" "<<c3.seats<<" "<<c3.type<<endl;
    return 0;
}