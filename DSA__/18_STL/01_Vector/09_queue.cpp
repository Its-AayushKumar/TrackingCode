#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    queue<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    queue<int> s2;

    s2.swap(s);

    while (!s2.empty())
    {
        cout << s2.front() << " ";
        s2.pop();
    }

    return 0;
}