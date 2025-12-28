#include<iostream>
#include<map>
using namespace std;


int main(){

    int n;
    cout<<"Enter the number of input elements: ";
    cin>>n;
    int arr[n];
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]]++;
    }

    int max =0,maxEle,minEle,min=INT_MAX;
    for(auto it:mpp){
        if(it.second>max){
            max = it.second;
            maxEle = it.first;
        }
        if(it.second<min){
            min = it.second;
            minEle = it.first;
        }
    }

    cout<<"The element "<<maxEle<<" has max frequency of "<<max<<" times."<<endl;
    cout<<"The element "<<minEle<<" has min frequency of "<<min<<" times."<<endl;

    return 0;
}