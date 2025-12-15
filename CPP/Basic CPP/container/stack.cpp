#include<iostream>
using namespace std;

void stacks(){
    stack<int> st;
    st.push(1);
    st.push(3);
    st.emplace(4);
    st.top() = st.top()+5;
    cout<<st.top();
    cout<<endl<<st.size();
}

int main(){
    stacks();
}