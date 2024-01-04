/**********************//*
 * \file   Administrator.cpp
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 ***********************/

#include "Administrator.h"
#include <string>
#include <fstream>

using namespace std;

Administrator::Administrator(){}

void Administrator::addEmployee() {
    // Get employee details
	int employeeCount = 0;
    std::string name, contactNumber;

	std::cout << "Enter employee name: ";
    std::cin.ignore(); // Ignore any leftover newline characters
    std::getline(std::cin, name);

    std::cout << "Enter contact number: ";
    std::getline(std::cin, contactNumber);

    // Generate username and password
    std::string username = "employee" + std::to_string(employeeCount + 1);
    std::string password = "Password@123";

    // Output details to console
    std::cout << "Employee added:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Contact Number: " << contactNumber << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;


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

	// load data from files
	ConfigurationList* config = new ConfigurationList("data\\bankconfig.txt");
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

	char adminChoice;
	
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

double Administrator::calculateOverdraftCharge() {
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