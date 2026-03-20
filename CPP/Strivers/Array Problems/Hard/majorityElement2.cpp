#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int el1=INT_MIN,el2=INT_MIN,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(cnt1==0 && el2!=nums[i]){
            cnt1 +=1;
            el1 = nums[i];
        }
        else if(cnt2==0 && el1!=nums[i]){
            cnt2 +=1;
            el2 = nums[i];
        }
        else if(el1 == nums[i]) cnt1+=1;
        else if(el2==nums[i]) cnt2+=1;
        else {
            cnt1-=1;
            cnt2-=1;
        }
    }
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==nums[i]) cnt1++;
        if(el2==nums[i]) cnt2++;
    }
    vector<int>ans;
    if(cnt1>n/3) ans.push_back(el1);
    if(cnt2>n/3) ans.push_back(el2);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}