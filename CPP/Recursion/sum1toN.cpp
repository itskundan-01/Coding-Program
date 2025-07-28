#include<iostream>
using namespace std;

int sum(int n){
    if(n==1) return 1;
    return n+sum(n-1);
}

int main(){
    int n;
    cout<<"Enter the value of N: ";
    cin>>n;
    int ans = sum(n);
    cout<<"The sum is: "<<ans;

}