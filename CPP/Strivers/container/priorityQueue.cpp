#include<iostream>

using namespace std;

void pqueue(){
    priority_queue<int>pq;
    pq.push(2);
    pq.push(3);
    pq.emplace(1);
    pq.push(5);
    cout<<pq.top();
    pq.pop();
    cout<<endl<<pq.top();
}

//Priority queue in reverse order as from minimum to maximum
void minHeap(){
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.emplace(3);
    pq.emplace(1);
    pq.emplace(5);
    pq.emplace(11);
    pq.emplace(51);
    cout<<pq.top();
    pq.pop();
    cout<<endl<<"The size of queue is: "<<pq.size()<<" and the top element is: "<<pq.top();
} 


int main(){
    pqueue();
    minHeap();
}
  