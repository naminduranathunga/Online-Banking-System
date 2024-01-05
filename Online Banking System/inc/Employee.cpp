/*****************************************************************//**
 * \file   Employee.cpp
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/

#include "BankingSystem.h"
#include "Employee.h"
#include "Account.h"
#include "Customer.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int customerCounter = 1;

Employee::Employee(const string& username, const string& password, int type, ConfigurationList* config) 
: User(username, password, type)
{
    // do nothing
}

void Employee::menu()
{
    bool loop = true;
    while (loop)
    {
        system("cls");
        cout << "==============================================" << endl;
        cout << "Welcome " << this->getUsername() << endl;
        cout << "==============================================" << endl;
        cout << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Create Account" << endl;
        cout << "3. Close Account" << endl;
        cout << "4. Deposit Money" << endl;
        cout << "5. Withdraw Money" << endl;
        cout << "6. View Account" << endl;
        cout << "7. Logout" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addcustomer();
            break;
        case 2:
            createaccount();
            break;
        case 3:
            closeaccount();
            break;
        case 4:
            depositmoney();
            break;
        case 5:
            withdrawmoney();
            break;
        case 6:
            viewaccount();
            break;
        case 7:
            cout << "Thanks for using our system" << endl;
            loop = false; // exit the loop
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        system("pause");
    }
}

void Employee::addcustomer()
{
    string customer_name, mobile_no, username, password;

    cout << "Enter customer details:" << endl;
    cout << "Name: ";
    cin >> customer_name;
    cout << endl;

    //ask username
    cout << "Enter a username: ";
    cin >> username;
    cout << endl;
    
    cout << "Mobile Number: ";
    cin >> mobile_no;
    cout << endl;

    cout << "Password: ";
    cin >> password;
    cout << endl;

    // Check if the username is already taken
    User* user = nullptr;
    try{
        user = User::fromFile(username);
        cout << "Username already taken." << endl;

    }catch (const char* msg){
        // Create a new customer
        user = new Customer(username, password, User::UserType::CUSTOMER);
        user->save();
        
        cout << "Customer created successfully." << endl;

    }catch(...){
        cout << "Error creating customer." << endl;
    }

}

void Employee::createaccount()
{
    int accountType;
    string customer_username;

    cout << "Enter customer's username: ";
    cin >> customer_username;

    // Check if the customer exists
    try
    {
        cout << customer_username << endl;
        User* user = User::fromFile("data\\users\\" + customer_username + ".txt");
        if (user->getType() != User::UserType::CUSTOMER){
            cout << "User is not a customer." << endl;
            return;
        }

        cout << "Select account type (1 - Saving, 2 - Current): ";
        cin >> accountType;

        if (accountType == 1 || accountType == 2)
        {
            // Generate a random account number
            long accountNumber = rand() % 9000000000 + 1000000000;
            Account* account = nullptr;
            if (accountType == 1)
            {
                // Create a Savings account
                account = new Account(accountNumber, customer_username, Account::AccountType::Savings, 0);
            }
            else
            {
                // Create a Current account
                account = new Account(accountNumber, customer_username, Account::AccountType::Current, 0);
            }
            account->save();

            Customer* customer = (Customer*)user;
            customer->addAccount(account);
            customer->save();

            delete account;

            cout << "Account created successfully. Account Number: " << accountNumber << endl;
        }
        else
        {
            cout << "Invalid account type selected." << endl;
        }

        delete user;
    }
    catch(const char* msg){
        cout << msg << endl;
    }catch(...){
        cout << "Error creating account." << endl;
    }
}

void Employee::closeaccount()
{

}

void Employee::depositmoney()
{
    long account_no;
    float depositamount;
    int date;

    cout << "Enter the account number: ";
    cin >> account_no;

    try
    {
        Account* account = Account::fromFromFile(account_no);

        cout << "Enter the deposit amount: ";
        cin >> depositamount;

        cout << "Enter the date: (-1 for current date)";
        cin >> date;

        if (date == -1)
        {
            date = this->system_ref->date;
        }

        account->deposit("Deposit", depositamount, date);

    }
    catch(const char* e)
    {
        // account does not exist
        cout << e << endl;
        return;
    }

}

void Employee::withdrawmoney()
{
    long account_no;
    float withdrawalamount;
    int date;

    cout << "Enter the account number: ";
    cin >> account_no;

    try
    {
        Account* account = Account::fromFromFile(account_no);

        cout << "Enter the withdraw amount: ";
        cin >> withdrawalamount;

        cout << "Enter the date: (-1 for current date)";
        cin >> date;

        if (date == -1)
        {
            date = this->system_ref->date;
        }

        account->withdraw("Deposit", withdrawalamount, date);

    }
    catch(const char* e)
    {
        // account does not exist
        cout << e << endl;
        return;
    }

}

void Employee::viewaccount()
{
    long account_no;
    float withdrawalamount;
    int date;

    cout << "Enter the account number: ";
    cin >> account_no;

    try
    {
        Account* account = Account::fromFromFile(account_no);
        account->showTransactions();
    }
    catch(const char* e)
    {
        // account does not exist
        cout << e << endl;
        return;
    }
}