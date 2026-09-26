#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

int main()
{
    deque<int> l = {1, 2, 3};

    l.emplace_back(1);
    l.push_back(2);
    l.push_front(3);
    l.push_front(5);

    for (int val : l)
    {
        cout << val << " ";
    }
    cout << endl;

    l.pop_back();
    l.pop_front();

    for (int val : l)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << l[0];
    return 0;
}
// the difference between list and deque is in deque dynamic array is used so we can also directly access the elements , in list double linked list is used 