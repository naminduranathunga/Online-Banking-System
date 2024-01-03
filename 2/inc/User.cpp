#include "User.h"

User::User(const string& uname, const string& pwd, int t)
    : username(uname), password(pwd), type(t) {}

const string& User::getUsername() const {
    return username;
}

bool User::authenticate(const string& inputPassword) const {
    return password == inputPassword;
}

int User::getType() const {
    return type;
}
