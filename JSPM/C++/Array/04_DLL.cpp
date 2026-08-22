#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name;
    string phone;
    Node*prev;
    Node*next;
};

Node*head = NULL;
Node*tail = NULL;

void addContact(){
    Node* newNode = new Node;

    cout<<"Enter Name: ";
    cin>> newNode->name;

    cout<<"Enter Phone Number: ";
    cin>> newNode->phone;
}


int main()
{
    
    return 0;
}