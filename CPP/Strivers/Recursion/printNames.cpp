#include<iostream>
using namespace std;

void printName(string name,int n){
    if(0>=n) return;
    cout<<name<<endl;
    printName(name,n-1);
}

int main(){
    int n;
    string name;
    cout<<"Enter the name: ";
    cin>>name;
    cout<<"Enter the number of times to be printed: ";
    cin>>n;
    printName(name,n);
}