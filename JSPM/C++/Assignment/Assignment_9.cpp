#include <iostream>
using namespace std;

int area(int x)
{
    return x * x;
}

int area(int l, int b)
{
    return l * b;
}
int area(float r)
{
    return 3.14 * r * r;
}

int main()
{
    int side, length, breadth, result;
    float radius;

    cout << "Enter side of square:";
    cin >> side;
    cout << "Enter length:";
    cin >> length;
    cout << "Enter breadth:";
    cin >> breadth;
    cout << "Enter Radius:";
    cin >> radius;

    result = area(side);
    cout << result << endl;

    result = area(length, breadth);
    cout << result << endl;

    result = area(radius);
    cout << result << endl;

    return 0;
}