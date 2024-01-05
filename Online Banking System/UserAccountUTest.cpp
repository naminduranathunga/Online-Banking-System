#include "inc/Account.h"
#include "inc/SavingsAccount.h"
#include "inc/CurrentAccount.h"
#include <iostream>
#include <string>

/**
 * Simple Unit Test for accounts
*/
string AccountTypeToString(Account::AccountType type){
    switch (type)
    {
    case Account::AccountType::Savings:
        return "Savings";
    case Account::AccountType::Current:
        return "Current";
    default:
        return "None";
    }
}

int main(){
    //create new users 

    //create a new accounts and add for each user

    //save the accounts

    //load the accounts

    //deposit and withdraw
}