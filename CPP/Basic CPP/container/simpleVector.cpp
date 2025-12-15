#include<iostream>
using namespace std;

int main(){
    vector<int>vct (5,14);
    vector<int>::iterator it = vct.begin();
    it++;
    cout<<*(it)<<endl;
    vct.push_back(5);
    vct.insert(vct.begin(),12); //To insert at the initial as 0th index - insert -> vct.begin(),element
    vct.insert(vct.begin()+2,54); //To insert at custom position by using begin+ the index, element
    vct[4] = 91;
    for(int i=0;i<vct.size();i++) cout<<vct[i]<<" ";
    cout<<"\nThe size of vector is : "<<vct.size();

    cout<<"\nPrinting from backside using - rend()\n";
    vector<int>::reverse_iterator iit = vct.rend();
    iit--;
    cout<<*(iit)<<" ";

    cout<<vct.at(3)<<"\nNow, Enter the element to update the element at 4th position in vector: ";
    int inp;
    cin>>inp;
    vct.at(3) = inp;
    cout<< "\nThe updated value at 4th position is: "<<vct.at(3)<<" and the full vector is: \n";
    for(int i: vct) cout<<i<<" ";
    cout<<endl;
    //Using Auto for printing in for loop of vector
    for(auto itr = vct.begin();itr!=vct.end();itr++) cout<<*itr<<" ";
    
}