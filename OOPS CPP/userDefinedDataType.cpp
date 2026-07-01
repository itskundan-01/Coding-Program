#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int roll;
    float cgpa;
};

int main(){
    Student s1; 
    s1.name = "Kundan";
    s1.roll = 30371;
    s1.cgpa = 9.03;

    cout<<s1.name<<" "<<s1.roll<< " "<< s1.cgpa<<endl;
}