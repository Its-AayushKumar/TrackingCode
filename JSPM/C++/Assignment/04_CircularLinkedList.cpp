#include <iostream>
#include <string>
using namespace std;

struct Contact
{
    string name;
    string phone;
    Contact *next;
};

class ContactBook
{
    Contact *last;

public:
    ContactBook()
    {
        last = NULL;
    }
    void addContact()
    {
        Contact *newContact = new Contact;

        cout << "Enter Name: ";
        cin >> newContact->name;

        cout << "Enter Phone Number: ";
        cin >> newContact->phone;

        if (last == NULL)
        {
            last = newContact;
            last->next = last;
        }
        else
        {
            newContact->next = last->next;
            last->next = newContact;
            last = newContact;
        }

        cout << "Contact added successfully.\n";
    }

    void displayContacts()
    {
        if (last == NULL)
        {
            cout << "Contact book is empty.\n";
            return;
        }

        Contact *temp = last->next;

        cout << "\n--- Contact List ---\n";

        do
        {
            cout << "Name: " << temp->name
                 << ", Phone: " << temp->phone << endl;

            temp = temp->next;

        } while (temp != last->next);
    }

    void searchContact()
    {
        if (last == NULL)
        {
            cout << "Contact book is empty.\n";
            return;
        }

        string name;
        cout << "Enter name to search: ";
        cin >> name;

        Contact *temp = last->next;

        do
        {
            if (temp->name == name)
            {
                cout << "Contact Found!\n";
                cout << "Name: " << temp->name << endl;
                cout << "Phone: " << temp->phone << endl;
                return;
            }

            temp = temp->next;

        } while (temp != last->next);

        cout << "Contact not found.\n";
    }

    void deleteContact()
    {
        if (last == NULL)
        {
            cout << "Contact book is empty.\n";
            return;
        }

        string name;
        cout << "Enter name to delete: ";
        cin >> name;

        Contact *current = last->next;
        Contact *previous = last;

        do
        {
            if (current->name == name)
            {
                // Only one contact
                if (current == last && current->next == last)
                {
                    last = NULL;
                }
                else
                {
                    previous->next = current->next;

                    if (current == last)
                        last = previous;
                }

                delete current;
                cout << "Contact deleted successfully.\n";
                return;
            }

            previous = current;
            current = current->next;

        } while (current != last->next);

        cout << "Contact not found.\n";
    }
};

int main()
{
    ContactBook book;
    int choice;

    do
    {
        cout << "\n===== CONTACT MANAGEMENT BOOK =====";
        cout << "\n1. Add Contact";
        cout << "\n2. Display Contacts";
        cout << "\n3. Search Contact";
        cout << "\n4. Delete Contact";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            book.addContact();
            break;

        case 2:
            book.displayContacts();
            break;

        case 3:
            book.searchContact();
            break;

        case 4:
            book.deleteContact();
            break;

        case 5:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
