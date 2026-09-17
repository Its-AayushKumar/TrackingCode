#include <iostream>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val)
{
    if (top >= n)
    {
        cout << "Stack overflow" << endl;
    }
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
    {
        if (top <= -1)
            cout << "Stack underflow " << endl;
        else
        {
            cout << stack[top]<<endl;
            top--;
        }
    }

void display(){
    for (int i = top ; i >= 0; i--){
        cout<<stack[i]<<endl;
    }
}
int main()
{
push(10);
push(11);
push(12);
push(13);
pop();
display();
    return 0;
}