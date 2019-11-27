#include <iostream>
#include <cstring>
using namespace std;

class Person{
	char* name;
	int age;
public:
	Person(const char* myname, int myage){
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age=myage;
	}

	Person& operator=(const Person& p){
		delete [] name;
		int len = strlen(p.name) + 1;
		char *temp = new char[len];
		strcpy(temp, p.name);
		name = temp;
		age = p.age;
		return *this;
	}
	
	void ShowPersonInfo() const{
		cout << "이름: " << name<<endl;
		cout <<"나이: " << age<<endl;
	}

	~Person(){
		delete[]name;
		cout << "called destructor!" <<endl;
	}
};

int main(void){
	Person man1("Lee", 29);
	Person man2("Pack", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	return 0;
}
