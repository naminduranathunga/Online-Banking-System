/*****************************************************************//**
 * \file   User.cpp
 * \brief
 *
 * \author Rashmi
 * \date   January 2024
 *********************************************************************/

#include "User.h"
#include "../lib/ConfigurationList.h"

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

// Namindu
User* User::fromFile(string filename) {
    ConfigurationList* config = new ConfigurationList(filename);
    config->LoadFromFile();
    if (!config->IsLoaded()){
        throw "User file not found";
    }

    string username = config->GetBlock("user")->GetPropertyValue("username");
    string password = config->GetBlock("user")->GetPropertyValue("password");
    int type = stoi(config->GetBlock("user")->GetPropertyValue("type"));

    //Create user according to the type

    return new User(username, password, type);
}


// Namindu
void User::save() {
    ConfigurationList* config = new ConfigurationList("data/users/" + this->username + ".txt");
    config->AddBlock("user");
    config->GetBlock("user")->AddProperty("username", this->username);
    config->GetBlock("user")->AddProperty("password", this->password);
    config->GetBlock("user")->AddProperty("type", to_string(this->type));
    config->SaveToFile();
}

// Namindu
void User::menu() {
    std::cout << "Welcome " << this->username << endl;
    system("pause");
}