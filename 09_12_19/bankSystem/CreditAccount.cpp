#include "CreditAccount.h"
void CreditAccount::Deposit(int money){
    int total = money + money * specialRate;
    Account::Deposit(total);
}
