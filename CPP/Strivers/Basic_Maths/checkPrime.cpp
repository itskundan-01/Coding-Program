#include<iostream>
using namespace std;

bool prime(int n){
    int count=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            count +=1;
            if(i!=n/i) count +=1;
        }
        if(count>2) break;
    }
    if(count==2) return true;
    else return false;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    bool isPrime = prime(n);
    if(isPrime==true) cout<<n<<" is a Prime Number.";
    else cout<<n<<" is not a Prime Number.";
}