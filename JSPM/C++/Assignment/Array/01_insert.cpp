#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, pos, value;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the position you want to insert :";
    cin >> pos;

    if (pos < 0 || pos > n)
    {
        cout << "Invalid position" << endl;
        return 0;
    }

    cout << "Enter the value to insert: ";
    cin >> value;

    
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

     arr[pos] = value;

    n++;

    cout << "Array after insertion:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}