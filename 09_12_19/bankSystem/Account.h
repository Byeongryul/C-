#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <cstring>
using namespace std;
class Account{
    private:
        int accID;
        int balance;
        char * cusName;
    public:
        Account(int ID, int money, char* name);
        Account(const Account & ref);
        int GetAccID() const;
        virtual void Deposit(int money);
        int Withdraw(int money);
        void ShowAccInfo() const;
        ~Account();
};
#endif
