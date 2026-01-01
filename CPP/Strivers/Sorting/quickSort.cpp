#include<iostream>
using namespace std;

int qs(int* arr, int low,int high){
    int i=low, j =high, pivot =low;
    if(low<high){
        
        while(i<j){
            while(arr[i]<=arr[pivot] && i<=high) i++;
            while(arr[j]>arr[pivot] && j>=low) j--;
            if(i<j) swap(arr[i],arr[j]);  
        }
        if(j<i) swap(arr[j],arr[pivot]);
    }
    return j;
}

void quickSort(int* arr,int low, int high){
    if(low<high){
        int pivot = low;
        int pIndex = qs(arr,low,high);
        quickSort(arr,low,pIndex-1);
        quickSort(arr,pIndex+1,high);
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    quickSort(arr,0,n-1);
    for(int i:arr) cout<<i<<"\t";
}