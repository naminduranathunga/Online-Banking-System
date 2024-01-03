#include "inc/Account.h"

int main(){
    Account acc;
    acc.load(123456789);
    acc.deposit(123456789,"Deposit",1000,1);
    acc.withdraw(123456789,"Withdraw",500,1);
    acc.save(123456789,1,1000,"Deposit",1500);
    return 0;
}