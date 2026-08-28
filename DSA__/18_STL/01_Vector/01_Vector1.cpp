#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec; //0

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.emplace_back(5);
    
    vec.pop_back();
    for(int val : vec){
        cout<<val<<" ";
    }
    cout<<endl;

    cout<<"val at idx 2"<<vec[3]<<" or "<<vec.at(2)<<endl;
    return 0;
}