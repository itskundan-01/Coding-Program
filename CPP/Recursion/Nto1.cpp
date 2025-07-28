#include<iostream>
using namespace std;

void Nto1(int x){
    if(x<=0){
        cout<<0<<" ";
        return;
    }
    else if(x==1){
        cout<<1<<" ";
        return;
    }
    cout<<x<<" ";
    Nto1(x-1);
}

int main(){
    int n;
    cout<<"Enter the value of N:"<<endl;
    cin>>n;
    Nto1(n);
}