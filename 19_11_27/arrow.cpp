#include <iostream>
using namespace std;

class Point{
private:		
	int x, y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y){}

	friend istream & operator >>(istream & si, Point& p);
	friend ostream & operator <<(ostream & so, const Point& p);
};

istream & operator >> (istream & si, Point& p){
	si >> p.x >> p.y;
	return si;
}

ostream & operator << (ostream & so, const Point& p){
	so << p.x << " " << p.y;
	return so;
}

int main(void){
	Point pos1;
	cout << "x,y 좌표순으로 입력 : ";
	cin >> pos1;
	cout << pos1;
	return 0;
}
