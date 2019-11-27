#include <iostream>
using namespace std;

class Statistics{
	int capacity;
	int size;
	int *p;
public:
	Statistics(int n = 10){
		capacity = n;
		size = 0;
		p = new int[capacity];
	}
	~Statistics(){
		if(p) delete[]p;
	}
	Statistics & operator << (int n);
	Statistics & operator >> (int& avg);
	bool operator !();
	Statistics & operator ~ ();
};

Statistics& Statistics::operator << (int n){
	if(size == capacity){
		int*q = new int [capacity*2];
		for(int i = 0;i < capacity; ++i){
			q[i] = p[i];
		}
		capacity *=2;
		int *temp = p;
		p = q;
		delete[] temp;
	}
	p[size++] = n;
	return *this;
}

Statistics & Statistics::operator >> (int& avg){
	int sum = 0;
	for(int i = 0; i < size; ++i)
		sum += p[i];
	avg = sum / size;
	return * this;
}

bool Statistics::operator!(){
	if(size == 0) return true;
	else return false;
}

Statistics& Statistics::operator ~(){
	for(int i = 0; i < size; i++)
		cout << p[i]<<' ';
	cout << endl;
	return *this;
}

int main() {
	Statistics stat;
	if (!stat) cout << "new notthing"<<endl;
	int x[5];
	cout << "5 input data :";
	for (int i = 0; i < 5; i++)cin >> x[i];
	for (int i = 0; i < 5; i++)stat << x[i];
	stat << 100 << 200;
	~stat;

	int avg;
	stat >> avg;
	cout << "avg=" << avg <<endl;
	return 0;
}
