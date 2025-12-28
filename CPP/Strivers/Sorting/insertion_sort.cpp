#include<iostream>
using namespace std;

void insertion_sort(int* arr,int n){
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1] > arr[j]){
            swap(arr[j-1],arr[j]);
            j--;
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<"\t";
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    insertion_sort(arr,n);
}