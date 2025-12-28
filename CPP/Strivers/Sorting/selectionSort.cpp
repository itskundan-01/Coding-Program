#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-1;i++){
        int idx=i;
        for(int j=i+1;j<n;j++){
            if(v.at(idx)>v.at(j)){
                idx = j;
            }
        }
        swap(v[i],v[idx]);
    }
    for(int i : v) cout<<i<<"\t";

    return 0;
}