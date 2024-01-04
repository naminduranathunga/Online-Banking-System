/*****************************************************************//**
 * \file   Account.h
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Account
{
    private:
    string username;
    long account_no;
    float balance;
    int account_type;

    public:
    void load(long account_no);
    void save(long account_no,int day, float amount, string text, float balance);
    void deposit(long account_no,string text, float amount, int day);
    void withdraw(long account_no,string text, float amount, int day);
};

int main()
{
    Account account;
    long accountNumber;

    cout << "Enter the account number: ";
    cin >> accountNumber;

    // Load account details
    account.load(accountNumber);

    // Perform a deposit
    account.deposit(accountNumber, "Deposit", 100.0, 1);

    // Perform a withdrawal
    account.withdraw(accountNumber, "Withdrawal", 50.0, 2);

    // You can add more test cases as needed

    return 0;
}

