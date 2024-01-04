/*****************************************************************//**
 * \file   Account.cpp
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/
#include "Account.h"
#include <fstream>

using namespace std;

void Account::load(long account_no)
{
    // Load account details from a file
    ifstream file(to_string(account_no) + ".txt");
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

void Account::save(long account_no,int day, float amount, string text, float balance)
{
    ofstream file(account_no + ".txt", ofstream::app);
    file << "Date:" << day << "    ";
    file << "Amount" << amount << "    ";
    file << "Transaction" << text << "    ";
    file << "Balance" << balance << "    ";
    file << endl;
    file.close();
}

void Account::deposit(long account_no, string text, float amount, int day)
{
    // Deposit money into the account
    balance += amount;
    
    // Print a message about the deposit
    cout << "Date:" << day << "    ";
    cout << "Amount" << amount << "    ";
    cout << "Transaction" << text << "    ";
    cout << "Balance" << balance << "    ";
    cout << endl;
    
    // Save the updated account information to a file
    save(account_no,day,amount,text,balance);
}

void Account::withdraw(long account_no,string text, float amount, int day)
{
    if (amount <= balance)
    {
        // Withdraw money from the account
        balance -= amount;
    
        // Print a message about the deposit
        cout << "Date:" << day << "    ";
        cout << "Amount" << amount << "    ";
        cout << "Transaction" << text << "    ";
        cout << "Balance" << balance << "    ";
        cout << endl;
    
        // Save the updated account information to a file
        save(account_no,day,amount,text,balance);
    }
}