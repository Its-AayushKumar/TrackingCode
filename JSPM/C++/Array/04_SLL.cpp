#include <iostream>
#include <string>
using namespace std;


struct Node
{
    string name;
    string phone;
    Node *next;
};


Node *head = NULL;


void addContact()
{
    Node *newNode = new Node;

    cout << "Enter Name: ";
    cin >> newNode->name;

    cout << "Enter Phone Number: ";
    cin >> newNode->phone;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Contact added successfully.\n";
}


void displayContacts()
{
    if (head == NULL)
    {
        cout << "Contact list is empty.\n";
        return;
    }

    Node *temp = head;

    cout << "\n--- Contact List ---\n";

    while (temp != NULL)
    {
        cout << "Name  : " << temp->name << endl;
        cout << "Phone : " << temp->phone << endl;
        cout << "-------------------\n";

        temp = temp->next;
    }
}


void searchContact()
{
    string name;

    cout << "Enter name to search: ";
    cin >> name;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->name == name)
        {
            cout << "Contact Found!\n";
            cout << "Name  : " << temp->name << endl;
            cout << "Phone : " << temp->phone << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Contact not found.\n";
}


void deleteContact()
{
    string name;
    cout << "Enter name to delete: ";
    cin >> name;
    Node *temp = head;
    Node *prev = NULL;
    
    while (temp != NULL && temp->name != name)
    {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL)
    {
        cout << "Contact not found.\n";
        return;
    }
    
    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;

    cout << "Contact deleted successfully.\n";
}


int main()
{
    int choice;
    do
    {
        cout << "\n===== CONTACT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Contact\n";
        cout << "2. Delete Contact\n";
        cout << "3. Search Contact\n";
        cout << "4. Display Contacts\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact();
            break;

        case 2:
            deleteContact();
            break;

        case 3:
            searchContact();
            break;

        case 4:
            displayContacts();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
