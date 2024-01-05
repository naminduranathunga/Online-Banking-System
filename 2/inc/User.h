#ifndef USER_H
#define USER_H 1


#include <iostream>
#include <string>
using namespace std;

//Namindu
#define USER_TYPE_ADMINISTRATOR 1
#define USER_TYPE_BANK_EMPLOYEE 2
#define USER_TYPE_CUSTOMER 3

//Namindu
class BankingSystem;

class User {
public:
    /**
     * Note: Remove the user type class and use the above #define constants instead.
    */
    class UserType {
    public:
        static const int ADMINISTRATOR = 1;
        static const int BANK_EMPLOYEE = 2;
        static const int CUSTOMER = 3;
    };
    BankingSystem* system_ref;

    User(const string& username, const string& password, int type);

    const string& getUsername() const;

    bool authenticate(const string& inputPassword) const;

    int getType() const;

    // Namindu
    static User* fromFile(string filename);

    // Namindu
    virtual void save();

    // Namindu
    virtual void menu();

protected:
    string username;
    string password;
    int type;
};

#endif // !USER_H