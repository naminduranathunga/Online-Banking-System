/*****************************************************************//**
 * \file   Administrator.h
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 *********************************************************************/

#include <iostream>
#include "../lib/ConfigurationList.h"
#include <cmath>

using namespace std;


class Administrator {
public:
    int day;
    double annualInterestRate;
    
    Administrator();
    void addEmployee(string employeeName);

    void increaseDateByOne();

    void setAnnualInterest();

    void checkOverdrafts();

    double calculateOverdraftCharge(double overdraftAmount);

    double calculateAnnualInterest();
};



