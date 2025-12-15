#include<iostream>
using namespace std;

void que(){
    queue<int> q;
    q.emplace(5);
    q.emplace(10);
    q.emplace(15);
    q.push(2);
    cout<<q.back();
    q.pop();
    cout<<"\nIs empty:"<<q.empty()<<endl;
    cout<<endl<<q.front()<<" "<<q.size();
    cout<<"\n The last element is: "<<q.back();
}


int main(){
    que();
}