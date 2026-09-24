#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>vec = {1,2,3,4,5};
    cout<<"vec.begin :"<<*(vec.begin())<<endl;
    cout<<"vec.end :"<<*(vec.end())<<endl;
    // end give the nth postion not the n-1  th position

    vector<int>::iterator it;

    for(it = vec.begin();it != vec.end();it++)
    {
        cout<<*(it)<<" ";
    }
    cout<<endl;

    vector<int>::reverse_iterator itt;

    for(itt = vec.rbegin();itt != vec.rend();itt++)
    {
        cout<<*(itt)<<" ";
    }
    cout<<endl;

    return 0;
}