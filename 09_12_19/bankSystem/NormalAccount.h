#ifndef NORMALACCOUNT_H
#define NORMALACCOUNT_H
#include "Account.h"
class NormalAccount : public Account {
    private:
        int interRate = 3;
    public:
        void Deposit(int money);
};
#endif
