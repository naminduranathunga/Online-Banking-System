/*****************************************************************//**
 * \file   Administrator.cpp
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 *********************************************************************/

#include "Administrator.h"
#include <string>

using namespace std;

Administrator::Administrator(){
	
	// load data from files
	ConfigurationList* config = new ConfigurationList("..\\data\\bankconfig.txt");
	try
	{
		config->LoadFromFile();
		string interestRate = config->GetBlock("bank")->GetPropertyValue("annual_interest_rate");
		string date = config->GetBlock("bank")->GetPropertyValue("day");
		annualInterestRate = std::stod(interestRate);
		day = std::stoi(date);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

void Administrator::addEmployee(string employeeName) {
    // ... (get employee details)
	cout << "Employee added: " << employeeName << endl;
}

void Administrator::increaseDateByOne() {
    // increase the date by 1 day
	day += 1;

    // Calculate daily interest for savings accounts
    double dailyInterest = (calculateAnnualInterest() / 365.0)   ;
    //savingsAccount.balance += dailyInterest;

    // Check overdrafts and add overdraft charge
    checkOverdrafts();
}

void Administrator::setAnnualInterest() {
	char adminChoice;
	double annualInterestRate  ;

	cout << "Do you want to change the Annual Interest rate " << annualInterestRate << "? (y/n): ";
	cin >> adminChoice;
	if(adminChoice == 'y') {
		cout << "Enter the Annual Interest rate: ";
		cin >> annualInterestRate;


    }
}


void Administrator::checkOverdrafts() {
    // ... (implementation)
	
        cout << "Overdraft charge added to account " << endl;
    
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
















