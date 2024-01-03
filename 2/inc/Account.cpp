#include "Account.h"
#include <fstream>

using namespace std;

void Account::load(string filename)
{
    // Load account details from a file
    ifstream file(filename + ".txt");
    if (file.is_open()) 
    {
        file >> account_no >> balance;
        file.close();
    } 
    else 
    {
        cout << "File not found." << endl;
    }
}

void Account::save()
{
}

void Account::deposit(string text, float amount, int day)
{
    // Deposit money into the account
    balance += amount;
    
    // Print a message about the deposit
    cout << "Date:" << day <<endl;
    cout << "Amount" << amount <<endl;
    cout << "Transaction" << text << endl;
    cout << "Balance" << balance << endl;
    cout << endl;
    
    // Save the updated account information to a file
    save();
}

void Account::withdraw(string text, float amount, int day)
{
    if (amount <= balance)
    {
        // Withdraw money from the account
        balance -= amount;
    
        // Print a message about the deposit
        cout << "Date:" << day <<endl;
        cout << "Amount" << amount <<endl;
        cout << "Transaction" << text << endl;
        cout << "Balance" << balance << endl;
        cout << endl;
    
        // Save the updated account information to a file
        save();
    }
}