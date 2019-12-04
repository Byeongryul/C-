#include <iostream>
using namespace std;

class Point{
private:
        int x, y;
public:
    Point(int x, int y) : x(x), y(y){
        cout << "Point 객체 생성" << endl;
    }

    ~Point(){
        cout << "Point 객체 소멸" << endl;
    }

    void SetPos(int x, int y){
        this->x = x;
        this->y = y;
    }

    friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p){
    os << "[" << p.x << ", " << p.y << "]" << endl;
    return os;
}


class SmartPtr{
private:
    Point * posptr;
public:
    SmartPtr(Point * ptr) : posptr(ptr) {}
    Point& operator*() const {return *posptr;}
    Point* operator->() const {return posptr;}
    ~SmartPtr() {delete posptr;}
};

int main(int argc, char *argv[]){
    SmartPtr sptr1(new Point(1, 2));
    SmartPtr sptr2(new Point(2, 3));
    SmartPtr sptr3(new Point(4, 5));
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;
    sptr1->SetPos(10, 20);
    sptr2->SetPos(30, 40);
    sptr3->SetPos(50, 60);
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;
    return 0;
}
