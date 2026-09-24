#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *insertFront(Node *head, int value)
{
    Node *neww = new Node;
    neww->data = value;
    neww->next = head;
    head = neww;

    return head;
}

Node *insertEnd(Node *head, int value)
{
    Node * end = new Node;
    end->next = NULL;
    end->data = value;
    if (head == NULL)
        return end;
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = end;
    return head;
}


Node *insertPos(Node *head, int pos, int value)
{
    if (pos == 1)
        return insertFront(head, value);

    Node *curr = head;
    for (int i = 1; i < pos - 1 && curr != NULL; i++)
        curr = curr->next; // stop ON the node before pos

    if (curr == NULL || pos < 1)
    {
        cout << "Invalid position" << endl;
        return head;
    }

    Node *neww = new Node;
    neww->data = value;

    neww -> next = curr -> next;
    curr-> next = neww;
    

    return head;
}
int main()
{
    Node *head = new Node;
    Node *one = new Node;
    Node *two = new Node;
    Node *three = new Node;
    head->data = 10;
    head->next = one;
    one->data = 20;
    one->next = two;
    two->data = 30;
    two->next = three;
    three->data = 40;
    three->next = NULL;
    // Node *neww = new Node;
    // neww->data = 5;
    // neww->next = head;
    // head = neww;

    head = insertFront(head, 5);
    head = insertEnd(head, 50);
    head = insertPos(head, 3, 99);
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << endl;
        curr = curr->next;
    }
    // cout<<head->data;
    return 0;
}