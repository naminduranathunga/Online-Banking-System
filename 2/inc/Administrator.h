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

    Administrator();

    void menu() override;
    
    void addEmployee();

    void increaseDateByOne();

    void setAnnualInterest();

    void checkOverdrafts(string account);

    double calculateOverdraftCharge(double amount);

    void calculateDailyInterest(string acc);

};

