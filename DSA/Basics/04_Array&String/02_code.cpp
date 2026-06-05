// 2D array
#include<iostream>
using namespace std;

int main()
{
    int arr[3][3];
    arr[2][3] = 34;

    cout<<arr[2][3]<<endl;
    cout<<arr[2][1]; // This will print garbage value
    return 0;
}