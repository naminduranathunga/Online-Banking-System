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

    double annualInterestRate;
    int day;

    Administrator();
    void addEmployee();

    void increaseDateByOne();

    void setAnnualInterest();

    void checkOverdrafts();

    double calculateOverdraftCharge();

    double calculateAnnualInterest();
};

