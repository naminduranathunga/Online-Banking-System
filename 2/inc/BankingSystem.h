/*****************************************************************//**
 * \file   BankingSystem.h
 * \brief  
 * 
 * \author Namindu
 * \date   January 2024
 *********************************************************************/

#pragma once

#include <iostream>
#include <string>

class Account {
};
class User {};

class BankingSystem{
public:
	/**
	 * Properties.
	 */
	User* currentUser = nullptr;
	Account* BankOwnAccount = nullptr;
	int date = 0;
	float annualInterestRate;

	/**
	* Methods.
	**/
	void login();

	/**
	 * @brief This function will be the entry point of the system and controlls the main program loop.
	 */
	void mainMenu();

	/**
	 * \brief Retrive user by username.
	 */
	User* getUserByUsername(std::string username){
		return nullptr;
	};

};
