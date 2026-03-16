#include<iostream>
#include<vector>
using namespace std;
int main(){
    int m,n;
    cout<<"Enter the size of Rows of Matrix: ";
    cin>>m;
    cout<<"Enter the size of Columns of Matrix: ";
    cin>>n;
    int matrix[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int left=0,right=n-1,top=0,bottom=m-1;

    while(left <= right && top <= bottom){
        for(int x=left;x<=right;x++){
            cout<<matrix[top][x]<<" ";
        }
        top+=1;
        for(int x=top;x<=bottom;x++){
            cout<<matrix[x][right]<<" ";
        }
        right -=1;
        if(top<=bottom){
            for(int x=right;x>=left;x--){
                cout<<matrix[bottom][x]<<" ";
            }
            bottom -=1;
        }
        if(left<=right){
            for(int x=bottom;x>=top;x--){
                cout<<matrix[x][left]<<" ";
            }
            left+=1;
        }
    }

}