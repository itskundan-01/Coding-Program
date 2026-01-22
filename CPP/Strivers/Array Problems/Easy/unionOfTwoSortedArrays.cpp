#include<iostream>
#include<set>
using namespace std;

void bruteforce(int* arr1, int* arr2, int n1, int n2){
    set<int>st;
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    cout<<"The union of both array is: [ ";
    for(auto it:st) cout<<it<<" ";
    cout<<"]";
}

int main(){
    int n1,n2;
    cout<<"Enter the size of 1st array: ";
    cin>>n1;
    int arr1[n1],arr2[n2];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the size of 2nd array: ";
    cin>>n2;
    cout<<"Enter the array elements: ";
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    bruteforce(arr1,arr2,n1,n2);
}