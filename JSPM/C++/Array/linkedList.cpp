#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // Create three nodes
    head = new Node();
    second = new Node();
    third = new Node();

    // Assign data
    head->data = 10;
    second->data = 20;
    third->data = 30;

    // Link nodes
    head->next = second;
    second->next = third;
    third->next = NULL;

    // Display linked list
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}