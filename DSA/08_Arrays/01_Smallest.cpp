#include <iostream>
using namespace std;

int main()
{
    int nums[] = {12, 34, 565, 78, 897, 56};
    int size = 6;

    int chotu = INT_MAX; // INT_MAX means positive infinity
    int bdaa = INT_MIN;

    for (int i = 0; i < size; i++)
    { // min , max
        if (nums[i] < chotu)
        {
            chotu = nums[i];
            bdaa = nums[i];
        }
        chotu = min(nums[i], chotu);
        bdaa = max(nums[i], bdaa);

        // either of methods could be used
    }
    cout << "Chotu = " << chotu << endl;
    cout << "Bdaa = " << bdaa << endl;

    return 0;
}