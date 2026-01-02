#include<iostream>
#include<set>
using namespace std;

void optimal(vector<int>&arr,int n){
    int i=0,j=1;
    while(j<n){
        if(arr[i]==arr[j]){
            j++;
        }
        else {
            arr[i+1] =arr[j];
            i++;
            j++;
        }
    }
    cout<<"\nThe optimal output is: \n";
    for(int x=0;x<=i;x++) cout<<arr[x]<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the Sorted array element: ";
    vector<int>arr(n);
    set<int>s;

    //Bruteforce approach

    for(int i=0;i<n;i++){
        cin>>arr[i];
        // s.insert(arr[i]);
    } 
    // arr.clear();
    // int index=0;
    // for(auto it : s){
    //     arr[index]=it;
    //     index++;
    //     cout<<it<<endl;
    // }
    optimal(arr,n);
}