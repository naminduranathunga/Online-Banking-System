#include "inc/Account.h"
#include "inc/SavingsAccount.h"
#include "inc/CurrentAccount.h"
#include <iostream>
#include <string>

/**
 * Simple Unit Test for accounts
*/
string AccountTypeToString(Account::AccountType type){
    switch (type)
    {
    case Account::AccountType::Savings:
        return "Savings";
    case Account::AccountType::Current:
        return "Current";
    default:
        return "None";
    }
}

int main(){
    //create a new accounts
    SavingsAccount* acc1 = new SavingsAccount(234673, "AC Holder 1", 1000);
    CurrentAccount* acc2 = new CurrentAccount(346335, "Blob", 1000);
    Account* acc3 = new Account(234675, "Peter", Account::AccountType::None, 1000);
    
    cout << "Account 1: " << acc1->getBalance() << "  Type: " << AccountTypeToString(acc1->account_type) << " Account No: " << acc1->getAccountNo() << endl;
    cout << "Account 2: " << acc2->getBalance() << "  Type: " << AccountTypeToString(acc2->account_type) << " Account No: " << acc2->getAccountNo() << endl;
    cout << "Account 3: " << acc3->getBalance() << "  Type: " << AccountTypeToString(acc3->account_type) << " Account No: " << acc3->getAccountNo() << endl;
    cout << "Creating accounts done" << endl << endl;

    //save the accounts
    acc1->save();
    acc2->save();
    acc3->save();


    //load the accounts
    SavingsAccount* acc4 = (SavingsAccount*)Account::fromFromFile(234673);
    CurrentAccount* acc5 = (CurrentAccount*)Account::fromFromFile(346335);
    Account* acc6 = Account::fromFromFile(234675);

    cout << "Account 4: " << acc4->getBalance() << "  Type: " << AccountTypeToString(acc4->account_type) << " Account No: " << acc4->getAccountNo() << endl;
    cout << "Account 5: " << acc5->getBalance() << "  Type: " << AccountTypeToString(acc5->account_type) << " Account No: " << acc5->getAccountNo() << endl;
    cout << "Account 6: " << acc6->getBalance() << "  Type: " << AccountTypeToString(acc6->account_type) << " Account No: " << acc6->getAccountNo() << endl;
    cout << "Saving & Loading accounts done" << endl << endl;

    //deposit and withdraw
    acc4->deposit("Deposit", 100, 1);
    acc5->deposit("Deposit", 100, 1);
    acc6->deposit("Deposit", 100, 1);

    acc4->withdraw("Withdraw", 50, 1);
    acc5->withdraw("Withdraw", 50, 1);
    acc6->withdraw("Withdraw", 50, 1);

    cout << endl;
    cout << "Account 4: " << acc4->getBalance() << "  Type: " << AccountTypeToString(acc4->account_type) << " Account No: " << acc4->getAccountNo() << endl;
    cout << "Account 5: " << acc5->getBalance() << "  Type: " << AccountTypeToString(acc5->account_type) << " Account No: " << acc5->getAccountNo() << endl;
    cout << "Account 6: " << acc6->getBalance() << "  Type: " << AccountTypeToString(acc6->account_type) << " Account No: " << acc6->getAccountNo() << endl;
    cout << "Bal Should be 1050\n Deposit & Withdraw done" << endl << endl;

    //show transactions
    cout<<"Transactions of Account No"<<acc4->getAccountNo()<<endl;
    acc4->showTransactions();
    cout << endl;
    cout<<"Transactions of Account No"<<acc5->getAccountNo()<<endl;
    acc5->showTransactions();
    cout << endl;
    cout<<"Transactions of Account No"<<acc6->getAccountNo()<<endl;
    acc6->showTransactions();
    cout << endl;
    cout << "Should have two records\n Showing transactions done" << endl << endl;

    cout << "All tests done" << endl;
    system("pause");
    return 0;
}