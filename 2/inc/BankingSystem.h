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

#include "Account.h"
#include "User.h"
#include "../lib/ConfigurationList.h"


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
