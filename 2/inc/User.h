#include <iostream>
#include <string>
using namespace std;

//Namindu
#define USER_TYPE_ADMINISTRATOR 1
#define USER_TYPE_BANK_EMPLOYEE 2
#define USER_TYPE_CUSTOMER 3

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

    User(const string& username, const string& password, int type);

    const string& getUsername() const;

    bool authenticate(const string& inputPassword) const;

    int getType() const;

    // Namindu
    static User* fromFile(string filename);

    // Namindu
    void save();

    // Namindu
    virtual void menu();

private:
    string username;
    string password;
    int type;
};


