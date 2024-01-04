/*****************************************************************//**
 * \file   Administrator.h
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 *********************************************************************/

#include <iostream>
#include "../lib/ConfigurationList.h"
#include <cmath>

using namespace std;

class Account {
public:
    string accountNumber;
    double balance;
};

class Administrator {
public:
    Administrator();
    void addEmployee(string employeeName);

    void increaseDateByOne(Account &savingsAccounts);

    void setAnnualInterest();

    void checkOverdrafts(Account &savingsAccounts);

    double calculateOverdraftCharge(double overdraftAmount);

    double calculateAnnualInterest();
};



