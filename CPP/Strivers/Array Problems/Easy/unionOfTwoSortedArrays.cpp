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

void optimal(int* arr1, int* arr2, int n1, int n2){
    vector<int>unionarr;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<=arr2[j]){
            if(unionarr.size()==0||unionarr.back()!=arr1[i]){
                unionarr.emplace_back(arr1[i]);
            }
            i++;
        }
        else{
            if(unionarr.size()==0 || unionarr.back()!=arr2[j]){
                unionarr.emplace_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
        if(unionarr.size()==0 ||unionarr.back()!=arr1[i]){
            unionarr.emplace_back(arr1[i]);
        }
        i++;
    }
    while(j<n2){
        if(unionarr.size()==0 ||unionarr.back()!=arr2[j]){
            unionarr.emplace_back(arr2[j]);
        }
        j++;
    }
    cout<<endl;
    for(int a = 0;a<unionarr.size();a++) cout<<unionarr[a]<<"\n";
}

int main(){
    int n1,n2;
    cout<<"Enter the size of 1st array: ";
    cin>>n1;
    int arr1[n1];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n1;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the size of 2nd array: ";
    cin>>n2;
    int arr2[n2];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n2;i++){
        cin>>arr2[i];
    }
    bruteforce(arr1,arr2,n1,n2);
    optimal(arr1,arr2,n1,n2);
}