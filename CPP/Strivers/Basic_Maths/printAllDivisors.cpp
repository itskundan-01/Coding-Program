#include<iostream>
#include<cmath>
using namespace std;


//Efficient method to count
void divisor(int n){
    int count = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            count++;          // count i as divisor
            if(i != n/i)      // avoid counting sqrt(n) twice
                count++;      // count n/i as divisor
        }
    }
    cout << "Total number of divisors: " << count;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    divisor(n);
}