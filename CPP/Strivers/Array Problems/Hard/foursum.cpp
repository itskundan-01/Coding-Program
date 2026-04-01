#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<"Enter the Target value: ";
    int target;
    cin>>target;
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j>0 && nums[j]==nums[j-1]) continue;
            int k=j+1;
            int l=n-1;
            while(k<l){
                long long sum=nums[i]+nums[j]+nums[k]+nums[l];
                if(sum==target){
                    ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                    k++;l--;
                    while(k<l && nums[k]==nums[k-1]) k++;
                    while(k<l && nums[l]==nums[l+1]) l--;
                }
                else if(sum<target)k++;
                else l--;
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