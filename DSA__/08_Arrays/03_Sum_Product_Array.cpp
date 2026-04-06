#include <iostream>
using namespace std;

int arraySum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int arrayProduct(int arr[], int n)
{
    int pro = 1;
    for (int i = 0; i < n; i++)
    {
        pro *= arr[i];
    }
    return pro;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5; // Size of array
    cout << "Sum of array is :" << arraySum(arr, n) << endl;
    cout << "Product of array is :" << arrayProduct(arr, n) << endl;
    return 0;
}