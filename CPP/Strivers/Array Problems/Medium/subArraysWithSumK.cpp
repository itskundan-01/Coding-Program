
//OPTIMAL SOLUTION
#include<iostream>
using namespace std;
int main(){
    int n,tar,cnt=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>nums(n);
    cout<<"Enter the Array Elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];
    cout<<"Enter the target sum: ";
    cin>>tar;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum +=nums[j];
            if(sum==tar) cnt +=1;
        }
    }
    cout<<"The output is: "<<cnt;
}










// //BETTER SOLUTION
// #include<iostream>
// using namespace std;
// int main(){
//     int n,tar,cnt=0;
//     cout<<"Enter the size of array: ";
//     cin>>n;
//     vector<int>nums(n);
//     cout<<"Enter the Array Elements: ";
//     for(int i=0;i<n;i++) cin>>nums[i];
//     cout<<"Enter the target sum: ";
//     cin>>tar;
//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j=i;j<n;j++){
//             sum +=nums[j];
//             if(sum==tar) cnt +=1;
//         }
//     }
//     cout<<"The output is: "<<cnt;
// }





// //BRUTE-FORCE SOLUTION

// #include<iostream>
// using namespace std;
// int main(){
//     int n,tar,cnt=0;
//     cout<<"Enter the size of array: ";
//     cin>>n;
//     vector<int>nums(n);
//     cout<<"Enter the Array Elements: ";
//     for(int i=0;i<n;i++) cin>>nums[i];
//     cout<<"Enter the target sum: ";
//     cin>>tar;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n;j++){
//             int sum = 0;
//             for(int k=i;k<=j;k++){
//                 sum +=nums[k];
//             }
//             if(sum==tar) cnt +=1;
//         }
//     }
//     cout<<"The output is: "<<cnt;
// }