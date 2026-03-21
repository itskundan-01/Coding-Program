#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;

//Optimal Solution
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum<0){
                j++;
            }
            else if(sum>0){
                k--;
            }
            else{
                vector<int>temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k&&nums[j]==nums[j-1]) j++;
                while(j<k && nums[k]==nums[k-1]) k--;
            }
        }
    }
    for(auto triplet : ans){
        for(int num : triplet){
            cout << num << " ";
        }
        cout << "\n";
    }
}

















// //Better Solution
// int main(){
//     int n;
//     cin>>n;
//     vector<int> nums(n);
//     for(int i=0;i<n;i++) cin>>nums[i];
//     //Solution code

//     set<vector<int>> st;
//     for(int i=0;i<n;i++){
//         set<int>hashmap;
//         for(int j=i+1;j<n;j++){
//             int k = - (nums[i]+nums[j]);
//             if(hashmap.find(k)!=hashmap.end()){
//                 vector<int>temp = {nums[i],nums[j],k};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashmap.insert(nums[j]);
//         }
//     }
//     for(auto triplet : st){
//         for(int num : triplet){
//             cout << num << " ";
//         }
//         cout << "\n";
//     }
// }