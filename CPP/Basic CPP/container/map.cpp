#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main(){

    map<int,int>m;
    m[1] =3;
    m[3] = 10;
    int inpkey = 1;
    if(m.find(inpkey) != m.end()){
        cout<<m.at(inpkey);
    }
    else cout<<"Key doesnot exist!!.";
    cout<<m.size();

}