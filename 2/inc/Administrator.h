
#include <iostream>
#include <vector>
#include <cmath>
//#include "System.h"

using namespace std;

class Account {
public:
    string accountNumber;
    double balance;

    Account(const std::string& accNum);
};

class Administrator {
public:
    void addEmployee(const string& employeeName);

    void increaseDateByOne(vector<Account>& savingsAccounts);

    void setAnnualInterest(double interestRate);

private:
    void checkOverdrafts(const vector<Account>& savingsAccounts);

    double calculateOverdraftCharge(double overdraftAmount) const;
};


