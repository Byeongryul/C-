#ifndef ACCOUNTHANDLER_H
#define ACCOUNTHANDLER_H
#include "Account.h"
#define MAKE 1
#define DEPOSIT 2
#define WITHDRAW 3
#define INQUIRE 4
#define EXIT 5
class AccountHandler{
    private:
        Account * accArr[100];
        int accNum;
    public:
        AccountHandler();
        void ShowMenu(void) const;
        void MakeAccount(void);
        void DepositMoney(void);
        void WithdrawMoney(void);
        void ShowAllAccInfo(void) const;
        ~AccountHandler();
};
#endif
