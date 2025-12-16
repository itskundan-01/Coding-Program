#include<iostream>
#include<vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> arr;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    arr.emplace_back(i);
                    arr.emplace_back(j);
                    break;
                }
            }
        }
        return arr;
    }
};