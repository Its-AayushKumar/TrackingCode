#include<iostream>
using namespace std;

int main()
{
    string s = "Aayush";
    int len = s.size();
    s[len-1] = 'i';
    cout<<s;
    return 0;
}