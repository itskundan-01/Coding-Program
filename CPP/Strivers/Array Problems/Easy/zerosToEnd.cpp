#include<iostream>
using namespace std;

void bruteZerotoEnd(int* arr, int n, int nz){
    int temp[nz],it=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp[it] = arr[i];
            it++;
        }
    }
    for(int i=0;i<n;i++){
        if(i<nz) arr[i] = temp[i];
        else arr[i] = 0;
        cout<<arr[i]<<endl;
    }
}

void optimalZerotoEnd(int* arr, int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(j==-1 && arr[i]==0) j=i;
        if(i>j && j!=-1 && arr[i]!=0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
    cout<<"The optimal sol is: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

int main(){
    int n,nz=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]!=0) nz++;
    }
    int a[n];
    for(int i=0;i<n;i++) a[i] = arr[i];
    bruteZerotoEnd(arr,n,nz);
    optimalZerotoEnd(a,n);

}