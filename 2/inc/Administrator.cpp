#include "Administrator.h"
using namespace std;

// Account class implementation
Account::Account(const string& accNum) : accountNumber(accNum), balance(0.0) {}

// Administrator class implementation
void Administrator::addEmployee(const string& employeeName) {
    // *****************  logic to add an employee
    cout << "Employee added: " << employeeName << endl;
}

void Administrator::increaseDateByOne(vector<Account>& savingsAccounts) {
    // ************** logic to increase the date by 1
    cout << "Date increased by one day." << endl;

    // Calculate daily interest for savings accounts
    for (auto& account : savingsAccounts) {
        double dailyInterest = (System::annualInterestRate / 365.0) * account.balance;
        account.balance += dailyInterest;
    }

    // Check overdrafts and add overdraft charge
    checkOverdrafts(savingsAccounts);
}

void Administrator::setAnnualInterest(double interestRate) {
    // Set annual interest rate from the system
    System::annualInterestRate = interestRate;
    cout << "Annual interest rate set to: " << interestRate << "%" << endl;
}

void Administrator::checkOverdrafts(vector<Account>& savingsAccounts) {
    // logic to check overdrafts and add overdraft charge
    for (const auto& account : savingsAccounts) {
        if (account.balance < 0) {
            double overdraftCharge = calculateOverdraftCharge(account.balance);
            account.balance -= overdraftCharge;
            cout << "Overdraft charge added to account " << account.accountNumber
                 << ": " << overdraftCharge << endl;
        }
    }
}

double Administrator::calculateOverdraftCharge(double overdraftAmount) const {
    // Implement logic to calculate overdraft charge
    return fabs(overdraftAmount) * 0.02;  // Example: 2% of overdraft amount
}
