#include<iostream>
#include<string>
using namespace std;

bool pal(int i,string inp,int n){
    if(i>=n/2) return true;
    if(inp[i]!=inp[n-i-1]) return false;
    return pal(i+1,inp,n);
}

int main(){
    string inp;
    cout<<"Enter the string: ";
    cin>>inp;
    bool isPal = pal(0,inp,inp.size());
    if(isPal==true)
    cout<<"String is Palindrome"<<endl;
    else cout<<"String is not a Palindrome"<<endl;
}