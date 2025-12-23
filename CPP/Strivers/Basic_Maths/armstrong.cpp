#include<iostream>
using namespace std;

void armstrong(int n){
    int sum=0,org=n;
    while(n>0){
        sum= sum+(pow((n%10),3));
        n /=10;
    }
    if(org==sum) cout<<"The number is armstrong."<<endl;
    else cout<<"The number is not an armstrong!!"<<endl;
}


int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    armstrong(n);
}