#include <iostream>
using namespace std;

class complexx
{
private:
    int real, img;

public:
    complexx(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    complexx operator+()
    {
        return complexx(real, img);
    }
    complexx operator-()
    {
        return complexx(-real, -img);
    }
    void display()
    {
        cout << " -->(" << real << " " << img << ")" << endl;
    }
};
int main()
{
    complexx c1(5, 3);
    cout << "original";
    c1.display();

    complexx c2 = +c1;
    cout << "After+";
    c2.display();

    complexx c3 = -c1;
    cout << "After-";
    c3.display();

    return 0;
}