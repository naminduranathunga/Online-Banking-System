#include "Customer.h"
#include "../lib/ConfigurationLoaderLib.h"

using namespace std;

// Namindu
Customer::Customer(const string& username, const string& password, int type, ConfigurationList* config = nullptr)
    : User(username, password, type) {
    this->accounts = vector<Account*>();

    if (config != nullptr) {
        // load accounts
        vector<PropertyBlock*> blocks = config->GetBlocks();
        for (int i = 0; i < blocks.size(); i++) {
            PropertyBlock* block = blocks[i];
            if (block->GetName() == "account") {
                /*
                Add to accounts vector

                string accountNumber = block->GetProperty("accountNumber");
                string accountType = block->GetProperty("accountType");
                string balance = block->GetProperty("balance");
                string interestRate = block->GetProperty("interestRate");
                string interestType = block->GetProperty("interestType");
                string dateCreated = block->GetProperty("dateCreated");
                string status = block->GetProperty("status");

                Account* account = new Account(accountNumber, accountType, balance, interestRate, interestType, dateCreated, status);
                this->accounts.push_back(account);*/
            }
        }
    }
}

// Namindu
void Customer::menu() {
    bool loop = true;
    while (loop){
        system("cls");
        cout << "=============================================="<<endl;
        cout << "Welcome " << this->getUsername() << endl;
        cout << "=============================================="<<endl;
        cout << endl;
        cout << "1. View Transections" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Logout" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "View Transections" << endl;
            break;
        case 2:
            cout << "Deposit Money" << endl;
            break;
        case 3:
            cout << "Withdraw Money" << endl;
            break;
        case 4:
            cout << "Thanks for using our system" << endl;
            loop = false; // exit the loop
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
        system("pause");
    }

    system("pause");    
}

// Namindu
void Customer::viewTransections() {
    cout << "=============================================="<<endl;
    cout << "View Transections" <<endl;
    cout << "=============================================="<<endl;
    cout << endl;
    int choice = this->AskUserToSelectAccount();
    if (choice == -1) return;

}


// Namindu
void Customer::depositMoney() {
    cout << "=============================================="<<endl;
    cout << "Deposit Money" <<endl;
    cout << "=============================================="<<endl;
    cout << endl;
    int choice = this->AskUserToSelectAccount();
    if (choice == -1) return;

    cout << "Deposit Money" << endl;
}


// Namindu
void Customer::withdrawMoney() {
    cout << "=============================================="<<endl;
    cout << "Withdraw Money" <<endl;
    cout << "=============================================="<<endl;
    cout << endl;
    int choice = this->AskUserToSelectAccount();
    if (choice == -1) return;
    
    cout << "Withdraw Money" << endl;
}


// Namindu
int Customer::AskUserToSelectAccount() {
    if (this->accounts.size() == 0) {
        cout << "No accounts found" << endl;
        return -1;
    }

    cout << "Select Account" <<endl;
    cout << endl;
    for (int i = 0; i < this->accounts.size(); i++) {
        //cout << i + 1 << ". " << this->accounts[i]->account_type << endl;
        cout << i + 1 << ". " << "account_type   --- acc_number" << endl;
    }
    
    int max_tries = 3;
    int tries = 0;
    while (tries < max_tries) {
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        choice--; // decrement by 1 to match the index
        if (choice < 0 || choice >= this->accounts.size()) {
            cout << "Invalid choice" << endl;
            tries++;
            continue;
        }

        return choice;
    }
    
    return -1;
}