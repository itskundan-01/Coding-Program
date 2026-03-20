#include<iostream>
using namespace std;

vector<int> generate(int row){
    int ans=1;
    vector<int> ansRow;
    ansRow.push_back(ans);
    for(int col=1;col<row;col++){
        ans = ans * (row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

int main(){
    int n;
    cout<<"Enter the no. of rows: ";
    cin>>n;
    vector<vector<int>> rows;
    for(int i=1;i<=n;i++){
        rows.push_back(generate(i));
    }
    for(int i = 0; i < rows.size(); i++){
        for(int j = 0; j < rows[i].size(); j++){
            cout << rows[i][j] << " ";
        }
        cout << endl;
    }
}