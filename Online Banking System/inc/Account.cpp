/*****************************************************************//**
 * \file   Account.cpp
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/
#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <fstream>

using namespace std;

// added by Namindu
Account::Account()
{
    username = "";
    account_no = 0;
    balance = 0;
    account_type = AccountType::None;
}

// Namindu
Account::Account(long account_no, string username, AccountType account_type, float balance)
{
    this->account_no = account_no;
    this->username = username;
    this->account_type = account_type;
    this->balance = balance;
}


Account::~Account()
{
}

//Namindu
Account* Account::fromFromFile(long account_no)
{
    ConfigurationList* acc_config = new ConfigurationList("data\\accounts\\" + to_string(account_no) + ".txt");
    acc_config->LoadFromFile();
    Account* acc;
    string username = "";
    AccountType account_type = AccountType::Savings;

    float balance = 0;
    if (acc_config->IsLoaded()){
        PropertyBlock* acc_prop = acc_config->GetBlock("account");
        username = acc_prop->GetPropertyValue("username");
        account_type = (AccountType)stoi(acc_prop->GetPropertyValue("account_type"));
        balance = stof(acc_prop->GetPropertyValue("balance"));
    }else{
        balance = 0;
        username = "";
    }

    //based on account type create the account
    switch (account_type)
    {
    case AccountType::Savings:
        acc = new SavingsAccount(account_no, username, balance);
        break;
    case AccountType::Current:
        acc = new CurrentAccount(account_no, username, balance);
        break;
    default:
        acc = new Account(account_no, username, AccountType::None, balance);
        break;
    }

    return acc;
}

//Himaya Kaumadi
void Account::save()
{
    PropertyBlock* acc_prop = nullptr;
    // Edited by Namindu
    ConfigurationList* acc_config = new ConfigurationList("data\\accounts\\" + to_string(account_no) + ".txt");
    acc_config->LoadFromFile();
    if (acc_config->IsLoaded()){
        // file exists
        acc_prop = acc_config->GetBlock("account");
        if (acc_prop == nullptr){
            acc_config->AddBlock("account");
            acc_prop = acc_config->GetBlock("account");
        }
    }else{
        // file does not exist
        acc_config->AddBlock("account");
        acc_prop = acc_config->GetBlock("account");
    }
    
    acc_prop->AddProperty("username", this->username);
    acc_prop->AddProperty("account_type", to_string(this->account_type));
    acc_prop->AddProperty("balance", to_string(this->balance));
    acc_config->SaveToFile();
    
}

//Himaya Kaumadi
void Account::deposit(string text, float amount, int day)
{
    // Deposit money into the account
    balance += amount;
    
    // Print a message about the deposit
    cout << "Date:" << day << "    ";
    cout << "Amount:" << amount << "    ";
    cout << "Transaction:" << text << "    ";
    cout << "Balance:" << balance << "    ";
    cout << endl;

    //append to transaction history
    ofstream file("data\\transactions\\" + to_string(account_no) + ".txt", ios::app);
    file << "Date:" << day << "    ";
    file << "Amount:" << amount << "    ";
    file << "Transaction:" << text << "    ";
    file << "Balance:" << balance << "    ";
    file << endl;
    file.close();
    
    // Save the updated account information to a file
    save();
}

//Himaya Kaumadi
void Account::withdraw(string text, float amount, int day)
{
    if (amount <= balance)
    {
        // Withdraw money from the account
        balance -= amount;
    
        // Print a message about the deposit
        cout << "Date:" << day << "    ";
        cout << "Amount:" << amount << "    ";
        cout << "Transaction:" << text << "    ";
        cout << "Balance:" << balance << "    ";
        cout << endl;

        //append to transaction history
        ofstream file("data\\transactions\\" + to_string(account_no) + ".txt", ios::app);
        file << "Date:" << day << "    ";
        file << "Amount:" << amount << "    ";
        file << "Transaction:" << text << "    ";
        file << "Balance:" << balance << "    ";
        file << endl;
        file.close();
    
        // Save the updated account information to a file
        save();
    }
}

//Himaya Kaumadi
void Account::showTransactions()
{
    // Print the account information
    system("cls");
    cout << "===========================================" << endl;
    cout << "Account Number: " << account_no << endl;
    cout << "Username: " << username << endl;
    cout << "Account Type: " << account_type << endl;
    cout << "Balance: " << balance << endl;
    cout << "===========================================" << endl;
    cout << endl;
    
    // Print the transaction history
    ifstream file("data\\transactions\\" + to_string(account_no) + ".txt");
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

// Namindu
float Account::getBalance()
{
    return balance;
}

// Namindu
long Account::getAccountNo()
{
    return account_no;
}