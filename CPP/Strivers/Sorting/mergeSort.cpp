#include<iostream>
using namespace std;

void merge(int* arr,int low, int mid, int high){
    int left = low, right = mid+1;
    vector<int>v;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            v.emplace_back(arr[left]);
            left ++;
        }
        else{
            v.emplace_back(arr[right]);
            right++;
        } 
    }
    while(left<=mid){
        v.emplace_back(arr[left]);
        left++;
    }
    while(right<=high){
        v.emplace_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = v[i-low];
    }
}

void merge_sort(int* arr,int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}



int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    merge_sort(arr,0,n-1);
    for(int i:arr)cout<<i<<"\t";
}