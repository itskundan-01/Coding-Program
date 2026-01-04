#include<iostream>
using namespace std;

void brutforceRotation(int* arr, int n, int d){
    d = d%n;
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }
    for(int i=0+d;i<n;i++){
        arr[i-d] = arr[i];
    }
    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void reverse(int* arr, int s, int e){
    while(s<=e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++; 
        e--;
    }
}

void optimalRotation(int* arr, int n, int d){
    reverse(arr,0,d-1);
    reverse(arr,d+1,n-1);
    reverse(arr,0,n-1);
    cout<<"The optimal rotation is: \n";
    for(int i=0;i<n;i++) cout<<arr[i]<<endl;
}

int main(){
    int n,d;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    int temp[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        temp[i]=arr[i];
    }
    cout<<"Enter the number of places to be rotated: ";
    cin>>d;
    brutforceRotation(arr,n,d);
    optimalRotation(temp,n,d);
}