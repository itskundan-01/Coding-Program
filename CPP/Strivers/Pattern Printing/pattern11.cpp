#include<iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int bin = 0;
        if(i%2==1) bin = 1;
        for(int j=0;j<i;j++){
            cout<<bin<<" ";
            if(bin==1) bin = 0;
            else bin = 1;
        }
        cout<<endl;
    }
    return 0;
}
