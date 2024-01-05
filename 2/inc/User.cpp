#include "User.h"
#include "Customer.h"
#include "Employee.h"
#include "Administrator.h"
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

    delete config;
    //Create user according to the type
    if (type == User::UserType::CUSTOMER){
        return new Customer(username, password, type, config);
    } else if (type == User::UserType::BANK_EMPLOYEE){
        return new Employee(username, password, type);
    } else if (type == User::UserType::ADMINISTRATOR){
        return new Administrator(username, password, type);
    }

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

    delete config;
}

// Namindu
void User::menu() {
    std::cout << "Welcome " << this->username << "  Type:" << this->type <<endl;
    system("pause");
}