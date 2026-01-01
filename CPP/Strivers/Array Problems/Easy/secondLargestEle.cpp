#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int max,sMax;
    for(int i=0;i<n;i++){
        cin>>v.at(i);
        if(i==0) max=v[0];
        if(v.at(i)>max) max = v.at(i);
    }
    sMax=INT_MIN;
    for(int i=0;i<n;i++){
        if(v[i]>sMax && (v[i] != max)) sMax=v[i];
    }
    if(sMax==INT_MIN) cout<<"There is no second largest element because All the elements are equal";
    else cout<<"The Second largest element of the array is: "<<sMax<<endl;
}