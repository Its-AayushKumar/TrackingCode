#include <iostream>
#include <vector>
using namespace std;

int rbs(vector<int> arr, int tar, int st, int end)
{
    if(st <= end){
        int mid = st + (end - st)/2;

        if(tar > arr[mid]){
            return rbs(arr,tar,mid+1,end);
        }
        else if(tar<arr[mid]){
            return rbs(arr,tar,st,mid-1);
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12}; // odd size array
    int tar1 = 12;

    // cout<<binarySearch(arr1,tar1)<<endl;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12}; // even size array
    int tar2 = 0;

    cout << rbs(arr2, tar2,0,arr2.size()) << endl;

    return 0;
}