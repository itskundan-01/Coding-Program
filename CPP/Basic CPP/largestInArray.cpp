#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    int Arr[n];
    int lar;
    cout<<"Enter the Array elements: ";
    for(int i=0;i<n;i++){
        cin>>Arr[i];
        if(i==0) lar = Arr[0];
        if(lar<Arr[i]) lar = Arr[i];
    }
    cout<<"The Largest element of the Array is: "<<lar<<endl;

}