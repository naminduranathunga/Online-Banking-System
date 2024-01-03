/*****************************************************************//**
 * \file   Account.h
 * \brief  
 * 
 * \author Himaya Kaumadi
 * \date   January 2024
 *********************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Account
{
    private:
    string username;
    long account_no;
    float balance;
    int account_type;
    string file_name;

    public:
    void load(long account_no);
    void save(long account_no,int day, float amount, string text, float balance);
    void deposit(long account_no,string text, float amount, int day);
    void withdraw(long account_no,string text, float amount, int day);
};