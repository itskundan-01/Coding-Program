#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int rev=0;
    while(n>0){
        rev = (rev*10)+n%10;
        n /=10;
    }
    cout<<"The reversed number is: "<<rev<<endl;
}