#include "Administrator.h"

// Account class implementation
Account::Account(const std::string& accNum) : accountNumber(accNum), balance(0.0) {}

// Administrator class implementation
void Administrator::addEmployee(const std::string& employeeName) {
    // Implement logic to add an employee
    std::cout << "Employee added: " << employeeName << std::endl;
}

void Administrator::increaseDateByOne(std::vector<Account>& savingsAccounts) {
    // Implement logic to increase the date by 1
    std::cout << "Date increased by one day." << std::endl;

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
    std::cout << "Annual interest rate set to: " << interestRate << "%" << std::endl;
}

void Administrator::checkOverdrafts(const std::vector<Account>& savingsAccounts) {
    // Implement logic to check overdrafts and add overdraft charge
    for (const auto& account : savingsAccounts) {
        if (account.balance < 0) {
            double overdraftCharge = calculateOverdraftCharge(account.balance);
            account.balance -= overdraftCharge;
            std::cout << "Overdraft charge added to account " << account.accountNumber
                      << ": " << overdraftCharge << std::endl;
        }
    }
}

double Administrator::calculateOverdraftCharge(double overdraftAmount) const {
    // Implement logic to calculate overdraft charge
    return fabs(overdraftAmount) * 0.02;  // Example: 2% of overdraft amount
}
