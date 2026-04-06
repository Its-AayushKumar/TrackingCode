#include <iostream>
using namespace std;

void swapMaxMin(int arr[], int n)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {

        swap(mini = min(arr[i], mini), maxi = max(arr[i], maxi));
    }
}
int main()
{
    int arr[] = {1, 23, 454, 67, 8};
    int n = 5;
    cout << swapMaxMin(arr, n) << endl;
    return 0;
}