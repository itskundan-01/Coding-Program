#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array (less than 1000): ";
    cin>>n;
    int arr[n], hash[1001]={0};
    for(int i=0;i<n;i++){
        cin>>arr[i];
        hash[arr[i]]++;
    }
    cout<<"Unique elements (with only frequency one) are: ";
    for(int i=0;i<1001;i++){
        if(hash[i]==1) cout<<i<<" ";
    }

}