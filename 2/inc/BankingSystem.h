/*****************************************************************//**
 * \file   BankingSystem.h
 * \brief  
 * 
 * \author Namindu
 * \date   January 2024
 *********************************************************************/

#ifndef BANKINGSYSTEM_H
#define BANKINGSYSTEM_H

#include <iostream>
#include <string>

#include "User.h"
#include "../lib/ConfigurationList.h"

class Account;

class BankingSystem{
public:
	/**
	 * Properties.
	 */
	User* currentUser = nullptr;
	Account* BankOwnAccount = nullptr;
	int date;
	float annualInterestRate;

	/**
	* Methods.
	**/
	/**
	 * \brief Initilize bank profile and load data from files in the constructor.
	*/
	BankingSystem();

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

#endif // !BANKINGSYSTEM_H