/*****************************************************************//**
 * \file   Account.h
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/
#ifndef ACCOUNT_H
#define ACCOUNT_H 1

#include <iostream>
#include <string>

#include "../lib/ConfigurationLoaderLib.h"


using namespace std;

class Account
{
    protected:
        long account_no;
        float balance;

    public:
        enum AccountType{
            None = 0,
            Savings = 1,
            Current = 2
        };
        // publically accessible variables
        string username;
        AccountType account_type;


        Account();
        Account(long account_no, string username, AccountType account_type, float balance);
        ~Account();
        static Account* fromFromFile(long account_no);
        void save();
        void deposit(string text, float amount, int day);
        void withdraw(string text, float amount, int day);
        void showTransactions();
        float getBalance();
        long getAccountNo();

};

#endif // ACCOUNT_H