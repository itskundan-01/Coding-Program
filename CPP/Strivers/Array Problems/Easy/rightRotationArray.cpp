#include<iostream>
using namespace std;

void bruteRotation(int* arr,int n, int d){
    int temp[d];
    for(int i=n-d;i<n;i++){
        temp[i-(n-d)] = arr[i];
    }
    for(int i=n-d-1;i>=0;i--){
        arr[i+d] = arr[i];
    }
    for(int i=0;i<d;i++){
        arr[i] = temp[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;        
    }
}

void reverse(int* arr, int s, int e){
    while(s<e){
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++; 
        e--;
    }
}

void optimalRotation(int* arr, int n, int d){
    reverse(arr,0,n-d-1);
    reverse(arr,n-d,n-1);
    reverse(arr,0,n-1);
    cout<<"The optimal right array rotation : \n";
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
    cout<<"Enter the number of places to be rotated from right: ";
    cin>>d;
    d = d%n;
    bruteRotation(arr,n,d);
    optimalRotation(temp,n,d);
}