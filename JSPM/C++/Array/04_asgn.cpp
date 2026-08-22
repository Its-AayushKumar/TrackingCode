#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;
    cout << "Enter the maximum degree for first polynomial" << endl;
    cin >> n1;
    cout << "Enter the maximum degree for second polynomial" << endl;
    cin >> n2;
    if (n1 > n2)
        n3 = n1;
    else
        n3 = n2;
    int poly1[n3 + 1] = {0}, poly2[n3 + 1] = {0}, polyS[n3 + 1] = {0};
    for (int i = 0; i <= n1; i++)
    {
        cout << "Enter value of " << i << "degree element for first polynomial:" << endl;
        cin >> poly1[i];
    }

    for (int i = 0; i <= n2; i++)
    {
        cout << "Enter value of " << i << "degree element for second polynomial:" << endl;
        cin >> poly2[i];
    }

    for (int i = 0; i <= n3; i++)
    {
        polyS[i] = poly1[i] + poly2[i];
        // cout<<"The coefficient x^"<<i<<"is:"<<polyS[i]<<endl;
        cout << polyS[i] << "x^" << i;
        if (i != n3)
        {
            cout << "+";
        }
    }
    return 0;
}