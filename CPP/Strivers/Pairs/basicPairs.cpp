#include<iostream>
using namespace std;
//We can create nested pair and print them and use them as well
void Pair(){
    pair<int, pair<int,int>> p = {1, { 2, 3 } };
    cout<<p.first<<", "<<p.second.second<<" and "<<p.second.first;
}
//we can create the pair with array as well as each element/position will contain pair with '.first' and '.second'
pair<int,int> arrPair(){
    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    cout<<endl<<arr[0].first<<" and "<<arr[2].second;
    return make_pair(arr[1].first, arr[1].second);
}


int main(){
    Pair();
    pair<int,int> res = arrPair();
    cout<<"The pair at 2nd Element is : "<<res.first<<" and "<<res.second;
}