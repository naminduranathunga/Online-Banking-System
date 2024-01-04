/*****************************************************************//**
 * \file   Employee.cpp
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/

#include "Employee.h"
#include "Account.h"
#include "Customer.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int customerCounter = 1;

void Employee::addcustomer()
{
    Customer customer;

    cout << "Enter customer details:" << endl;
    cout << "Name: ";
    cin >> customer_name;
    
    cout << "Mobile Number: ";
    cin >> mobile_no;

    // Generate a username based on the counter
    string username = "customer" + to_string(customerCounter);
    customerCounter++;

    // Set a common password
    string password = "Password@1234";

    // Display the generated username
    cout << "Username: " << username << endl;

    // Set the generated username and common password in the customer object
    customer.setUsername(username);
    customer.setPassword(password);

    // Save customer details to a file
    ofstream customerFile(username + ".txt");
    if (customerFile.is_open())
    {
        customerFile << "Name: " << customer_name << endl;
        customerFile << "Mobile Number: " << mobile_no << endl;
        // Add more customer details as needed
        customerFile.close();
    }
    else
    {
        cerr << "Error creating customer file." << endl;
    }
}

void Employee::createaccount()
{
    int accountType;
    
    cout << "Select account type (1 - Saving, 2 - Current): ";
    cin >> accountType;

    if (accountType == 1 || accountType == 2)
    {
        // Generate a random account number
        long accountNumber = rand() % 9000000000 + 1000000000;

        if (accountType == 1)
        {
            // Create a Savings account
            // You can implement logic to create a Savings account using the Account class
            // For example: Account::createSavings(accountNumber);
        }
        else
        {
            // Create a Current account
            // You can implement logic to create a Current account using the Account class
            // For example: Account::createCurrent(accountNumber);
        }

        cout << "Account created successfully. Account Number: " << accountNumber << endl;
    }
    else
    {
        cout << "Invalid account type selected." << endl;
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

    cout << "Enter the deposit amount: ";
    cin >> depositamount;

    cout << "Enter the date: ";
    cin >> date;

    Account::deposit("Deposit", depositamount, date);
}

void Employee::withdrawmoney()
{
    long account_no;
    float withdrawalamount;
    int date;

    cout << "Enter the account number: ";
    cin >> account_no;

    cout << "Enter the withdrawal amount: ";
    cin >> withdrawalamount;

    cout << "Enter the date:";
    cin >> date;

    Account::withdraw("Withdraw", withdrawalamount, date);
}

void Employee::viewaccount()
{

}