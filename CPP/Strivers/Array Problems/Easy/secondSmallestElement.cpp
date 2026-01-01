#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int min,sMin=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>v.at(i);
        if(i==0) min=v[i];
        if(v[i]<min){
            sMin = min;
            min = v[i];
        }
        else if(v[i]>min && v[i]<sMin) sMin = v[i];
    }
    cout<<"The second smallest element is: "<<sMin<<endl;
}