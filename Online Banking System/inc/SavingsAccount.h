/**
 * @file SavingsAccount.h
 * 
 * @brief SavingsAccount class definition
 * @author Namindu
 * @date 2024-01-04
 */

#ifndef __SAVINGSACCOUNT_H__
#define __SAVINGSACCOUNT_H__ 1

#include "Account.h"

class SavingsAccount : public Account {
public:
    //constrictors almost same as Account
    SavingsAccount():Account(){account_type = AccountType::Savings;};
    SavingsAccount(long account_no, string username, float balance):Account(account_no, username, AccountType::Savings, balance){};
};

#endif // __SAVINGSACCOUNT_H__