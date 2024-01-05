/**
 * @file Customer.h
 * @brief 
 * 
 * @date 2024-01-03
 * @author Namindu Ranathunga
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H 1

#include <vector>
#include "User.h"
#include "Account.h"
#include "../lib/ConfigurationLoaderLib.h"

class Customer : public User {
    public:
        Customer(const string& username, const string& password, int type, ConfigurationList* config = nullptr);
        void menu() override;
        void viewTransections();
        void depositMoney();
        void withdrawMoney();
        void addAccount(Account* account);
        void save() override; // override

    private:
        vector<Account*> accounts;

        int AskUserToSelectAccount();  // returns the index of the selected account
};

#endif // !CUSTOMER_H