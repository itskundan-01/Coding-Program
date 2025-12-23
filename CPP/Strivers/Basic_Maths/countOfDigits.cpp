#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int count=log10(n)+1;
    cout<<"The count of digits in "<<n<<" is: "<<count<<endl;
}