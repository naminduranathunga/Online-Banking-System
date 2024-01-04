#include "Customer.h"

using namespace std;

// Namindu
Customer::Customer(const string& username, const string& password, int type, ConfigurationList* config)
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
                string accountNumber = block->GetPropertyValue("account_no");
                this->accounts.push_back(Account::fromFromFile(stol(accountNumber)));
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
            viewTransections();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
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

}

// Namindu
void Customer::viewTransections() {
    cout << "=============================================="<<endl;
    cout << "View Transections" <<endl;
    cout << "=============================================="<<endl;
    cout << endl;
    int choice = this->AskUserToSelectAccount();
    if (choice == -1) return;

    Account* account = this->accounts[choice];
    account->showTransactions();
}


// Namindu
void Customer::depositMoney() {
    cout << "=============================================="<<endl;
    cout << "Deposit Money" <<endl;
    cout << "=============================================="<<endl;
    cout << endl;
    int choice = this->AskUserToSelectAccount();
    if (choice == -1) return;

    cout << "Enter amount to deposit: ";
    float amount;
    cin >> amount;

    Account* account = this->accounts[choice];
    account->deposit("DEPOSIT", amount, 0);
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
    
    cout << "Enter amount to withdraw: ";
    float amount;
    cin >> amount;

    Account* account = this->accounts[choice];
    account->withdraw("WITHDRAW", amount, 0);
    
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
        Account* account = this->accounts[i];
        cout << i + 1 << ". " << "account_type:";
        cout << (account->account_type == Account::AccountType::Savings?"Savings":account->account_type == Account::AccountType::Current?"Current":"Other");
        cout << " --- Account No.:" << account->getAccountNo() << "  --- Balance:" << account->getBalance() << endl;
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


void Customer::addAccount(Account* account) {
    this->accounts.push_back(account);
    save();
}

void Customer::save() {
    ConfigurationList* config = new ConfigurationList("data/users/" + this->username + ".txt");
    config->AddBlock("user");
    config->GetBlock("user")->AddProperty("username", this->username);
    config->GetBlock("user")->AddProperty("password", this->password);
    config->GetBlock("user")->AddProperty("type", to_string(this->type));

    // save accounts
    for (int i = 0; i < this->accounts.size(); i++) {
        Account* account = this->accounts[i];
        config->AddBlock("account");
        config->GetBlock("account")->AddProperty("account_no", to_string(account->getAccountNo()));
        config->GetBlock("account")->AddProperty("account_type", to_string(account->account_type));
    }
    config->SaveToFile();
}