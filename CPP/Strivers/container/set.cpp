#include<iostream>
#include<set>
using namespace std;

void setfn(){
    set<int> st;
    st.emplace(4);
    st.emplace(2);
    st.emplace(32);
    st.emplace(2);
    st.emplace(4);

    auto it = st.find(3);
    cout<<(it!=st.end());
    cout<<st.count(32);

}


int main(){
    setfn();
}