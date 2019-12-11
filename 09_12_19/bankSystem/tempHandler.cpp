#include "AccountHandler.h"
AccountHandler::AccountHandler(){
    accNum = 0;
}
void AccountHandler::ShowMenu(void) const{
    cout << "-----Menu------" << endl;
    cout << "1. 개좌개설" << endl;
    cout << "2. 입    금" << endl;
    cout << "3. 출    금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}
void AccountHandler::MakeAccount(void){
    int id, balance;
    char name[100];
    cout << "[계좌개설]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "이  름: ";
    cin >> name;
    cout << "입금액: ";
    cin >> balance;
    accArr[accNum++] = new Account(id, balance, name);
}
void AccountHandler::DepositMoney(void){
    int id, balance;
    cout << "[입    금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "입금액: ";
    cin >> balance;

    int loc = 0;
    for(; loc < accNum; ++loc){
        if(accArr[loc]->GetAccID() == id) break;
    }
    if(loc != accNum){
        accArr[loc]->Deposit(balance);
    }
    cout << "입금완료" << endl;
}
void AccountHandler::WithdrawMoney(void){
    int id, balance;
    cout << "[출   금]" << endl;
    cout << "계좌ID: ";
    cin >> id;
    cout << "출금액: ";
    cin >> balance;
    int loc = 0;
    for(; loc < accNum; ++loc){
        if(accArr[loc]->GetAccID() == id) break;
    }
    if(loc != accNum){
        accArr[loc]->Withdraw(balance);
    }
    cout << "출금완료" << endl;
}
void AccountHandler::ShowAllAccInfo(void) const{
    for(int i = 0; i < accNum; ++i){
        accArr[i]->ShowAccInfo();
    }
}
AccountHandler::~AccountHandler(){
    for(int i = 0; i < accNum; ++i){
        delete accArr[i];
    }
}
