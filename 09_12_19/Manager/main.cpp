#include <iostream>
#include <cstring>
using namespace std;

enum {MAKE = 1, SALARY, SUM, INQUIRE, EXIT};

class Employee{
    private:
        bool permanent;
        int id;
        char * name;
    protected:
        int salary;
        char rank;

    public:
        Employee(int id, char * name, bool permanent, int salary, char rank){
            this->id = id;
            this->name = new char[100];
            strcpy(this->name, name);
            this->permanent = permanent % 2;
            this->salary = salary;
            this->rank = rank;
        }
        void showInfo(){
            cout << "직원ID: " << id << endl;
            cout << "이  름: " << name << endl;
            cout << "임  금: " << salary << endl;
            cout << "랭  크: " << rank << endl;
            cout << "실제 임금: " << Salary() << endl;
            cout << "정규직: ";
            if(permanent == 0) cout << "정규직";
            else cout << "비정규직";
            cout << endl << endl;
        }
        void showSalaryInfo(){
            cout << "임  금: " << Salary() << endl;
            cout << endl;
        }
        virtual int Salary(){
            int sum = salary;
            switch(rank){
                case 'A':
                    sum = sum * (1.3);
                    break;
                case 'B':
                    sum = sum * (1.2);
                    break;
                case 'C':
                    sum = sum * (1.1);
                    break;
            }
            return sum;
        }
};

class TimeEmployee : public Employee{
    private:
        int time = 0;
    public:
        TimeEmployee(int id, char* name, bool permanent, int salary, char rank, int time) : Employee(id, name, permanent, salary, rank){
            this->time = time;
        }
        void AddWorkTime(int n){
            time += n;
        }
        int Salary(){
            int sum = salary;
            switch(rank){
                case 'A':
                    sum = sum * (1.3) * time;
                    break;
                case 'B':
                    sum = sum * (1.2) * time;
                    break;
                case 'C':
                    sum = sum * (1.1) * time;
                    break;
            }
            return sum;
        }
};

class ManagerHandler{
    private:
        int employeeNum = 0;
        Employee * employeeArr[100];
    public:
        void showManu(void) const{
            cout << "-----Menu------" << endl;
            cout << "1. 직원추가" << endl;
            cout << "2. 모든 급여 출력" << endl;
            cout << "3. 급여 합 출력" << endl;
            cout << "4. 계좌정보 전체 출력" << endl;
            cout << "5. 프로그램 종료" << endl;
        }
        void showAllInfo(void) const{
            for(int i = 0; i < employeeNum; ++i){
                employeeArr[i]->showInfo();
            }
        }
        void MakeEmployee(void){
            int permanent;
            int id, salary, time;
            char name[100];
            char rank;
            cout << "[직원추가]" << endl;
            cout << "직원ID: ";
            cin >> id;
            cout << "이  름: ";
            cin >> name;
            cout << "정규직(odd = 비정규직 or even = 정규직): ";
            cin >> permanent;
            cout << "급여: ";
            cin >> salary;
            cout << "Rank(A or B or C): ";
            cin >> rank;
            if('A' <= rank && rank <= 'C')
                if(permanent % 2 == 0){
                employeeArr[employeeNum++] = new Employee(id, name, permanent % 2, salary, rank);
                }
                else{
                    cout << "시  간: ";
                    cin >> time;
                employeeArr[employeeNum++] = new TimeEmployee(id, name, permanent % 2, salary, rank, time);
                }
            else
                cout << "rank는 A ~ C 입니다." << endl;
        }
        void showSalaryInfo(){
            for(int i = 0; i < employeeNum; ++i){
                employeeArr[i]->showSalaryInfo();
            }
        }

        void showSumInfo(){
            int sum = 0;
            for(int i = 0; i < employeeNum; ++i){
                sum += employeeArr[i]->Salary();
            }
            cout << "total :" << sum << endl << endl;
        }
};

int main(int argc, char * argv[]){
    int choice;
    ManagerHandler manager;
    while(1){
        manager.showManu();
        cin >> choice;
        switch(choice){
            case MAKE:
                manager.MakeEmployee();
                break;
            case SALARY:
                manager.showSalaryInfo();
                break;
            case SUM:
                manager.showSumInfo();
                break;
            case INQUIRE:
                manager.showAllInfo();
                break;
            case EXIT:
                return 0;
                break;
        }

    }
    return 0;
}
