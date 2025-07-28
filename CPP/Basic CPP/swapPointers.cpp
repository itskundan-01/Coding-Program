#include<iostream>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int a = 45;
    int b = 23;
    swap(&a,&b);
    cout<<"After Swapping the values are: ";
    cout<<a<<" and "<<b<<endl;
}

