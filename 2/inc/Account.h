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
    void load(string filename);
    void save();
    void deposit(string text, float amount, int day);
    void withdraw(string text, float amount, int day);
};