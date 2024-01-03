/*****************************************************************//**
 * \file   BankingSystem.cpp
 * \brief
 *
 * \author Namindu
 * \date   January 2024
 *********************************************************************/

#include "BankingSystem.h"

using namespace std;

BankingSystem::BankingSystem() {
	// load data from files
	ConfigurationList* config = new ConfigurationList("..\\data\\bankconfig.txt");
	try
	{
		config->LoadFromFile();
		string s = config->GetBlock("unnamed")->GetPropertyValue("name");
		cout << s << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
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
	User* user = getUserByUsername(username);
	//validate password

	//display error or go to user's main menu
}
