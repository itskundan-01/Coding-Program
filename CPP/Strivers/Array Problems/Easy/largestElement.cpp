#include<iostream>
#include<vector>
//To find the largest element in array
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int max;
    for(int i=0;i<n;i++){
        cin>>v.at(i);
        if(i==0) max=v.at(0);
        if(v.at(i)>max) max = v.at(i);
    }
    cout<<"The largest element is: "<<max;
}
