/*****************************************************************//**
 * \file   Administrator.h
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 *********************************************************************/

#include <iostream>
#include "../lib/ConfigurationList.h"
#include "User.h"
#include <cmath>

using namespace std;


class Administrator : public User{
public:

    double annualInterestRate;
    int day;

    Administrator(const string& username, const string& password, int type, ConfigurationList* config = nullptr);

    void menu() override;
    
    void addEmployee();

    void increaseDateByOne();

    void setAnnualInterest();

    void checkOverdrafts(string account);

    double calculateOverdraftCharge(double amount);

    void calculateDailyInterest(string acc);

};

