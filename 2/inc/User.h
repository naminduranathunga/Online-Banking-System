
#include <string>
using namespace std;

class User {
public:
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

private:
    string username;
    string password;
    int type;
};


