/*****************************************************************//**
 * \file   Employee.h
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/

#include <iostream>
#include <string>
#include "User.h"
#include "Account.h"
#include "../lib/ConfigurationLoaderLib.h"

using namespace std;

class Employee : public User
{
    private:
    long account_no;
    string username;
    string password;
    string customer_name;
    long mobile_no;
    float amount;

    public:
    Employee(const string& username, const string& password, int type, ConfigurationList* config = nullptr);
    void menu() override;
    void addcustomer();
    void createaccount();
    void closeaccount();
    void depositmoney();
    void withdrawmoney();
    void viewaccount();
};