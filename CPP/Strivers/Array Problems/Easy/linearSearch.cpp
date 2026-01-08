#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int sele;
    cout<<"Enter the element to be searched: ";
    cin>>sele;
    for(int i=0;i<n;i++){
        if(sele==arr[i]) {
            cout<<sele<<" found at index: "<<i<<endl;
            return 0;
        }
        
    }
    cout<<sele<<" not found."<<endl;
}