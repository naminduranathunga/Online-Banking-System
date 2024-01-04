/*****************************************************************//**
 * \file   Employee.h
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Employee
{
    private:
    long account_no;
    string username;
    string password;
    string customer_name;
    long mobile_no;
    float amount;

    public:
    void addcustomer();
    void createaccount();
    void closeaccount();
    void depositmoney();
    void withdrawmoney();
    void viewaccount();
};