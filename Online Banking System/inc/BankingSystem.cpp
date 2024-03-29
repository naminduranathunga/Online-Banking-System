/*****************************************************************//**
 * \file   BankingSystem.cpp
 * \brief
 *
 * \author Namindu
 * \date   January 2024
 *********************************************************************/

#include "BankingSystem.h"
#include "Account.h"

using namespace std;

BankingSystem::BankingSystem() {
	// load data from files
	ConfigurationList* config = new ConfigurationList("data\\bankconfig.txt");
	config->LoadFromFile();

	if (!config->IsLoaded()){
		cout << "Error loading configuration file" << endl;
		system("pause");
		exit(1);
	}
	
	PropertyBlock* bank = config->GetBlock("bank");
	date = stoi(bank->GetPropertyValue("day"));
	annualInterestRate = stof(bank->GetPropertyValue("annual_interest_rate"));
	string bank_acc_num = bank->GetPropertyValue("account_no");

	BankOwnAccount = new Account();
	
}

void BankingSystem::mainMenu() {
	while (1) {
		system("cls");
		cout << "Welcome to the LMN Bank" << endl;
		cout << "1. Login" << endl;
		cout << "2. Exit" << endl;
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;

		switch (choice) {
			case 1:
				login();
				break;
			case 2:
				exit(0);
				break;
			default:
				cout << "Invalid choice. Please try again." << endl;
				system("pause");
				break;
		}

	}
}

void BankingSystem::login() {
	system("cls");
	cout << "Enter your username: ";
	string username;
	cin >> username;
	cout << "Enter your password: ";
	string password;
	cin >> password;

	// get user by username
	User* user = nullptr;
	try
	{
		user = User::fromFile("data\\users\\" + username + ".txt");
	}
	catch(const char* e)
	{
		std::cerr << e << '\n';
	}
	catch(...){
		cout << "Error loading user file" << endl;
		system("pause");
		exit(1);
	}
	

	//validate password
	if (user->authenticate(password)) {
		this->currentUser = user;
		cout << "Login successful" << endl;
		system("pause");

		user->system_ref = this; // set the parent reference
		user->menu();
	}
	else {
		cout << "Invalid username or password" << endl;
		system("pause");
	}

	this->currentUser = nullptr;
	//test
	User *test = new User("test", "test", 1);
	test->save();
	//display error or go to user's main menu
}
