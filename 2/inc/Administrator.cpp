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

Administrator::Administrator() : User(username, password, type){}

void Administrator::addEmployee() {
    // Get employee details
    std::string name, contactNumber;
    int employeeCount;

    cout << "Enter the number of employees: ";
    cin >> employeeCount;

    for(int i = 0; i<employeeCount; i++) {
        cout << "Enter employee name: ";
        cin.ignore(); // Ignore any leftover newline characters
        getline(cin, name);

        cout << "Enter contact number: ";
        getline(cin, contactNumber);

        // Generate username and password
        string username = "employee" + to_string(employeeCount + 1);
        string password = "Password@123";

        ConfigurationList* config = new ConfigurationList("data/users/" + this->username + ".txt");
        config->AddBlock("user");
        config->GetBlock("user")->AddProperty("username", this->username);
        config->GetBlock("user")->AddProperty("password", this->password);
        config->GetBlock("user")->AddProperty("type", "employee");
        config->SaveToFile();

        // Output to the console
        cout << "Employee was added to the system.\nPlease enter the next employee." << endl;

        } 
    }


void Administrator::increaseDateByOne() {

    // load data from files
	ConfigurationList* config = new ConfigurationList("..\\data\\bankconfig.txt");
	try
	{
		config->LoadFromFile();
		string date = config->GetBlock("bank")->GetPropertyValue("day");
		day = std::stoi(date);

        char increaseDay;
        cout << "Do you want to increase the date (Day " << day << ") by one? (y/n): ";
        cin >> increaseDay;
        if(increaseDay == 'y') {
            // increase the date by 1 day
	        day += 1; 
            
            // Check overdrafts and add overdraft charge
            checkOverdrafts();
        }

        cout << "Current Date = Day " << day << endl;

        ConfigurationList *newconfig = new ConfigurationList("data/bankconfig.txt");
        config->GetBlock("bank")->AddProperty("day", to_string(day));

    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    

    // Calculate daily interest for savings accounts
    double dailyInterest = (calculateAnnualInterest() / 365.0)   ;
    //savingsAccount.balance += dailyInterest;

}

void Administrator::setAnnualInterest() {

	// load data from files
	ConfigurationList* config = new ConfigurationList("..\\data\\bankconfig.txt");
	try
	{
		config->LoadFromFile();
		string interestRate = config->GetBlock("bank")->GetPropertyValue("annual_interest_rate");
		annualInterestRate = std::stod(interestRate);

        char adminChoice;
        cout << "Do you want to change the Annual Interest rate " << annualInterestRate << "? (y/n): ";
        cin >> adminChoice;
        if(adminChoice == 'y') {
        cout << "Enter the new Annual Interest rate: ";
		cin >> annualInterestRate;
        }

        ConfigurationList *newconfig = new ConfigurationList("data/bankconfig.txt");
        config->GetBlock("bank")->AddProperty("annual_interest_rate", to_string(annualInterestRate));

    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
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

