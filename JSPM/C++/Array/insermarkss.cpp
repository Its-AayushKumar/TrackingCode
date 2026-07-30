#include <iostream>
using namespace std;

int marks[100];
int n;

void insert()
{
    int pos, value;

    cout << "Enter the position you want to insert:";
    cin >> pos;

    if (pos < 0 || pos > n)
    {
        cout << "Invalid position" << endl;
        return;
    }

    cout << "Enter the value to insert:";
    cin >> value;

    for (int i = n; i > pos; i--)
    {
        marks[i] = marks[i - 1];
    }

    marks[pos] = value;

    n++;

    cout << "Array after insertion:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }
    cout << endl;
}

void del(int pos){
if(n==0){
    cout<<"Array is empty:"<<endl;
}

if (pos < 0 || pos > n)
{
    cout << "Invalid position" << endl;
    return;
}

int removed = marks[pos];

for (int i = pos; i < n - 1; i++)
{
    marks[i] = marks[i + 1];
}
n--;
cout << "Deleted marks " << removed << "  from position  " << pos ;

cout << "Array after deletion:" << endl;
for (int i = 0; i < n; i++)
{
    cout << marks[i] << " ";
}
cout << endl;
}


int main()
{
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the array elements:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    // insert();
    del(2);

     return 0;
}