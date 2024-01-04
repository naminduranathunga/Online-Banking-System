

#ifndef __CURRENTACCOUNT_H__
#define __CURRENTACCOUNT_H__ 1
#include "Account.h"

class CurrentAccount : public Account {
public:
    //constrictors almost same as Account
    CurrentAccount():Account(){account_type = AccountType::Current;};
    CurrentAccount(long account_no, string username, float balance):Account(account_no, username, AccountType::Current, balance){};
};

#endif // __CURRENTACCOUNT_H__