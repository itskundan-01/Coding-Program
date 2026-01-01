#include<iostream>
using namespace std;

bool isSortedRotated(int arr[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > arr[(i+1)%n]) count++;
    }
    return (count <= 1);
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    bool isSorted = isSortedRotated(arr,n);
    if(isSorted==true)cout<<endl<<"The array is Rotated Sorted"<<endl;
    else cout<<"\nThe array is not rotated Sorted"<<endl;

    //Non rotated sorted check
    for(int i=1;i<n;i++){
        if(arr[i]<arr[i-1]){
            cout<<"False";
            return 0;
        }
    }
    cout<<"True";
    return 0;
}