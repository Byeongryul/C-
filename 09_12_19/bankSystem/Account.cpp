#include "Account.h"
Account::Account(int ID, int money, char* name){
    accID = ID;
    balance = money;
    this->cusName = new char[100];
    strcpy(this->cusName, name);
}
Account::Account(const Account & ref):Account(ref.accID, ref.balance, ref.cusName){
}
int Account::GetAccID() const{
    return accID;
}
void Account::Deposit(int money){
    this->balance += money;
}
int Account::Withdraw(int money){
    this->balance -= money;
    if(balance >= 0) return 1;
    this->balance += money;
    return 0;
}
void Account::ShowAccInfo() const{
    cout << "계좌ID: " << accID << endl;
    cout << "이  름: " << cusName << endl;
    cout << "잔  액: " << balance << endl;
}
Account::~Account(){
    if(cusName){
        delete[] cusName;
    }
}
