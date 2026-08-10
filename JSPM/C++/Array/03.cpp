#include <iostream>
#include <string>
using namespace std;
// Node for Linked List
struct Node
{
    char data;
    Node *next;
};
Node *top = NULL;
// Push operation
void push(char ch)
{
    Node *newNode = new Node;
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
}
// Pop operation()
char pop()
{
    if (top == NULL)
        return '\0';

    Node *temp = top;
    char value = temp->data;
    top = top->next;
    delete temp;
    return value;
}
// Peek operation
char peek()
{
    if (top == NULL)
        return '\0';
    return top->data;
}
// Check if stack is empty
bool isEmpty()
{
    return (top == NULL);
}
// Function to return precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}
// Function to convert Infix to Postfix
string infixToPostfix(string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];
        // Operand
        if (isalnum(ch))
        {
            postfix += ch;
        }
        // Left Parenthesis
        else if (ch == '(')
        {
            push(ch);
        }
        // Right Parenthesis
        else if (ch == ')')
        {
            while (!isEmpty() && peek() != '(')
            {
                postfix += pop();
            }
            pop(); // Remove '('
        }
        // Operator
        else
        {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
            {
                postfix += pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty())
    {
        postfix += pop();
    }
    return postfix;
}
int main()
{
    string infix;
    cout << "Enter Infix Expression: ";
    cin >> infix;
    cout << "Postfix Expression: " << infixToPostfix(infix);
    return 0;
}
