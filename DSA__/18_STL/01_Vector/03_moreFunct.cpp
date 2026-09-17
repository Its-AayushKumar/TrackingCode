#include<iostream>
using namespace std;
#include<vector>

int main()
{
    // erase

    vector<int> vec1 = {1,2,3,4,5};

    vec1.erase(vec1.begin()+1,vec1.begin()+3);

    for(int val: vec1){
        cout<<val<<" ";
    }
    cout<<endl;

    vec1.erase(vec1.begin()+1);

    for (int val : vec1)
    {
        cout << val << " ";  
    }
    cout << endl;

    // insert

    vec1.insert(vec1.begin()+1,2);

    for (int val : vec1)
    {
        cout << val << " ";
    }
    cout << endl; 

    // clear 
    vec1.clear();

    for (int val : vec1)
    {
        cout << val << " ";
    }
    cout << endl;
    cout<<"size:"<<vec1.size()<<endl;
    cout<<"capacity:"<<vec1.capacity()<<endl;

    // empty 
    cout<<"is empty :"<<vec1.empty()<<endl;
    
    return 0;
}