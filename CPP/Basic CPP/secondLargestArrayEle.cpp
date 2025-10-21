#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    int Arr[n];
    int lar,sLar;
    cout<<"Enter the Array elements: ";
    for(int i=0;i<n;i++){
        cin>>Arr[i];
        if(i==0){
             lar = Arr[0];
            sLar = lar;
        }
        if(lar<Arr[i]) lar = Arr[i];
        if(sLar>Arr[i]) sLar = Arr[i];
    }

    for(int i=0;i<n;i++){
        if(Arr[i]<lar && Arr[i]>sLar){
            sLar = Arr[i];
        }
    }

    cout<<"The Second Largest element of the Array is: "<<sLar<<endl;

}

//This code works well but is not the efficient one

//To be updated with efficient code with no multiple updation in sLar

//Will do it

/*
git add .
git commit -m "Content Updation"
git push origin main
*/