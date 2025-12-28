#include<iostream>
using namespace std;

void bubble_sort(int* arr,int n){
    for(int a=0;a<n;a++) cin>>arr[a];
    
    for(int i=0;i<n-1;i++){
        int didSwap =0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                didSwap=1;
            }

        }
        if(didSwap==0) break;
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<"\t";
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    bubble_sort(arr,n);
    
}