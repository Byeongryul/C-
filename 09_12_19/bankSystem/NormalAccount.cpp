#include "NormalAccount.h"
void NormalAccount::Deposit(int money){
    int total = money + money * interRate;
    Account::Deposit(total);
}
