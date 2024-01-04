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
#include <cmath>

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

            cout << "\nCurrent Date = Day " << day << endl;

            ConfigurationList *newconfig = new ConfigurationList("data/bankconfig.txt");
            config->GetBlock("bank")->AddProperty("day", to_string(day));

            char accType;
            cout << "\nAccount Types:\n"
                 << "\t1 - Savings\n\t2- Current";
            cout << "\nEnter the account type(1 or 2): ";
            cin >> accType;

            string accNumber;
            cout << "Enter the account number: ";
            cin.ignore(); // Ignore any leftover newline characters
            getline(cin, accNumber);

            switch (accType)
            {
            case '1':
                calculateDailyInterest(accNumber);
                break;
            case '2':
                checkOverdrafts(accNumber);
                break;
            default:
                cout << "Invalid Input!";
                break;
            }
        }
    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

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


void Administrator::checkOverdrafts(string account) {

    // load data from files
	ConfigurationList* config = new ConfigurationList("data\\accounts\\" + account + ".txt");
	try
	{
		config->LoadFromFile();
		string amount = config->GetBlock("account")->GetPropertyValue("balance");
		double currentBalance = std::stod(amount);

        if(currentBalance < 0) {
            cout << "\nYour current account has been over draft." << endl;
            double absoluteValue = std::abs(currentBalance);
            double value = calculateOverdraftCharge(absoluteValue);
            cout << "Overdraft charge: " << value;
            currentBalance = currentBalance - value;

            ConfigurationList *newconfig = new ConfigurationList("data\\accounts\\" + account + ".txt");
            config->GetBlock("account")->AddProperty("balance", to_string(currentBalance));
        }    

    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}    
    
}

double Administrator::calculateOverdraftCharge(double amount) {
    const double chargingPercentage = 0.04;
    double overdraftCharge = chargingPercentage*amount;
    return overdraftCharge;
}

void Administrator::calculateDailyInterest(string acc) {

    // load data from files
	ConfigurationList* config = new ConfigurationList("data\\accounts\\" + acc + ".txt");
	try
	{
		config->LoadFromFile();
		string amount = config->GetBlock("account")->GetPropertyValue("balance");
		double currentBalance = std::stod(amount);

        string interestRate = config->GetBlock("bank")->GetPropertyValue("annual_interest_rate");
		annualInterestRate = std::stod(interestRate);

        double dailyInterest = (annualInterestRate/365.0)*currentBalance;

        cout << "\nToday Interest Percentage: " << dailyInterest;
        currentBalance = currentBalance + dailyInterest;

        ConfigurationList *newconfig = new ConfigurationList("data\\accounts\\" + acc + ".txt");
        config->GetBlock("account")->AddProperty("balance", to_string(currentBalance));

        cout << "Interest was added to the account" << endl; 

    }
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}   
}
	




