#include<iostream>
using namespace std;

int main(){
    int arr[12],min=INT_MAX, max=INT_MIN,avg =0 ,sum=0,maxM=0,minM=0;
    cout<<"Enter the array elements: ";
    for(int i=0;i<12;i++){
        cin>>arr[i];
        if(arr[i]>max){
            max = arr[i];
            maxM =i;
        }
        if(arr[i]<min){
            min = arr[i];
            minM =i;
        }
        sum = sum+arr[i];
    }
    avg = sum/12;

    cout<<"The sum is : "<<sum<<endl<< " and average is: "<<avg<<"\n max rainfall month : "<<maxM+1<<endl<<"min rainfall month :"<<minM+1<<endl;
}