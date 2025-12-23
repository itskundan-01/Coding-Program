#include<iostream>
using namespace std;
//By using extra space
void pal(int n){
    int rev=0,p=n;
    while(n>0){
        rev = (rev*10)+n%10;
        n /=10;
    }
    if(p==rev) cout<<"It's a palindrome."<<endl;
    else cout<<"Not a palindrome!"<<endl;
}


int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    pal(n);
}