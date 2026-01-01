#include<iostream>
using namespace std;

int partition(int* arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i >= j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}


int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    quickSort(arr,0,n-1);
    for(int i:arr) cout<<i<<"\t";
}