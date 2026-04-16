#include <iostream>
using namespace std;

int main()
{
    int correctCard = 1234;
    int balance = 5000;
    int cardNumber{};
    int wdamt;

    cout << "Enter Card Number :";
    cin >> cardNumber;

    try
    {
        if (cardNumber == correctCard)
        {
            cout << "Enter Withdrawal amount :";
            cin >> wdamt;
            if (wdamt > balance)
            {
                throw "Insufficient balance !";
            }
            else
            {
                balance -= wdamt;
                cout << "Withdrawal successful" << endl;
                cout << "Remaining balance:" << balance;
            }
        }
        else
        {
            throw "Invalid card!!";
        }
    }
    catch (const char *s)
    {
        cout << s << endl
             << "Thank you 😊" << endl;
    }
    return 0;
}