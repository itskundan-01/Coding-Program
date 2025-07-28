#include<iostream>
using namespace std;

void OnetoN(int x){
    if(x<=0) return;
    OnetoN(x-1);
    cout<<x<<" ";
}

int main(){
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    OnetoN(n);
}