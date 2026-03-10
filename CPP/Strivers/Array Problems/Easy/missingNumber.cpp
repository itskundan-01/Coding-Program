#include<iostream>
#include<vector>

//To Find the missing number in array

using namespace std;
int missingNumber(vector<int>& nums);

int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the available elements: ";
    for(int i=0;i<n-1;i++){
        cin >> nums[i];
    }
    int res = missingNumber(nums);

    cout<<"The missing element is: "<<res;
}

int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;
        int xor1=0;
        int xor2=0;
        int res = 0;
        for(int i=0;i<n-1;i++){
            xor1 = xor1 ^ (i+1);
            xor2 = xor2 ^ nums[i];
        }
        res = xor1^xor2;
        return res;
    }
