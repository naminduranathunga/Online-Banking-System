/*****************************************************************//**
 * \file   Administrator.cpp
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 *********************************************************************/

#include "Administrator.h"
#include <fstream>

using namespace std;

Administrator::Administrator(){}

void Administrator::addEmployee(string employeeName) {
    // ... (get employee details)
	cout << "Employee added: " << employeeName << endl;
}

void Administrator::increaseDateByOne(Account &savingsAccount) {
    // increase the date by 1 day
    

    // Calculate daily interest for savings accounts
    double dailyInterest = (calculateAnnualInterest() / 365.0) * savingsAccount.balance;
    savingsAccount.balance += dailyInterest;

    // Check overdrafts and add overdraft charge
    checkOverdrafts(savingsAccount);
}

void Administrator::setAnnualInterest() {
	char adminChoice;
	double interestRate;
	cout << "Do you want to change the Annual Interest rate? (y/n): ";
	cin >> adminChoice;
	if(adminChoice == 'y') {
		cout << "Enter the Annual Interest rate: ";
		cin >> interestRate;

        // Open the file for writing
        ofstream outFile("annual_interest_rate.txt");

        // Check if the file is open
        if (outFile.is_open()) {
            // Write the new interest rate to the file
            outFile << interestRate;

            // Close the file
            outFile.close();

            cout << "Annual interest rate set to: " << interestRate << "%" << endl;

        } else {
            cerr << "Error opening the file for writing." << endl;
        }
    }
}


void Administrator::checkOverdrafts(Account &savingsAccount) {
    // ... (implementation)
	if (savingsAccount.balance < 0) {
        double overdraftCharge = calculateOverdraftCharge(savingsAccount.balance);
        savingsAccount.balance -= overdraftCharge;
        cout << "Overdraft charge added to account " << savingsAccount.accountNumber
             << ": " << overdraftCharge << endl;
    }
}

double Administrator::calculateOverdraftCharge(double overdraftAmount) {
    // ... (implementation)
}

double Administrator::calculateAnnualInterest() {
    // ... (implementation)
}

int main()
{
	Administrator a;
	a.setAnnualInterest();
}
















