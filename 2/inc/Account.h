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

    public:
    void load();
    void save();
    void deposit(string text, float amount);
    void withdraw(string text, float amount);
};