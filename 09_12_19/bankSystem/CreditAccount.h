#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H
#include "Account.h"
class CreditAccount : public Account {
    private:
        int specialRate = 2;
    public:
        void Deposit(int money);
};
#endif
