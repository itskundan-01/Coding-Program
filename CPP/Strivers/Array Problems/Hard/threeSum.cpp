#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
//Better Solution
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    //Solution code

    set<vector<int>> st;
    for(int i=0;i<n;i++){
        set<int>hashmap;
        for(int j=i+1;j<n;j++){
            int k = - (nums[i]+nums[j]);
            if(hashmap.find(k)!=hashmap.end()){
                vector<int>temp = {nums[i],nums[j],k};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            hashmap.insert(nums[j]);
        }
    }
    for(auto triplet : st){
        for(int num : triplet){
            cout << num << " ";
        }
        cout << "\n";
    }
}