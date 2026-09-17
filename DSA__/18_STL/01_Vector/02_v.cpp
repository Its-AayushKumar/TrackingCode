#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec1 = {1,2,3,4,5};

    for(int val : vec1){
        cout<< val <<" ";
    }
    cout<<endl; 

    vector<int> vec2 (10,-1);  // Dynamic programming - tabulation DP[][]

    for(int val:vec2){
        cout<< val<<" ";
    }
    cout<<endl;
    
    return 0;
}