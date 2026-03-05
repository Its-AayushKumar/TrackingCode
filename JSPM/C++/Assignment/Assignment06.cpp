#include <iostream>
using namespace std;

// Bankaccount
class BankAccount
{
protected:
    string accountHolder;
    float balance;

    BankAccount()
    {
        accountHolder = "Joe";
        balance = 100000.90;
    }

    // Display details
    void showbalance()
    {
        cout << "Account holder's name :" << accountHolder << endl;
        cout << "Account holder's balance :" << balance << endl;
    }

protected:
    void updateBalance(float amount)
    {
        balance = amount;
    }
};
//  Transaction
class Transaction : public BankAccount
{
};

int main()
{

    return 0;
}