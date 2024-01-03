/**
 * @file Customer.h
 * @brief 
 * 
 * @date 2024-01-03
 * @author Namindu Ranathunga
*/

#pragma once

#include <vector>
#include "User.h"
#include "Account.h"

class Customer : public User {
    public:
        Customer(const string& username, const string& password, int type, ConfigurationList* config = nullptr);
        void menu();
        void viewTransections();
        void depositMoney();
        void withdrawMoney();

    private:
        vector<Account*> accounts;

        int AskUserToSelectAccount();  // returns the index of the selected account
};