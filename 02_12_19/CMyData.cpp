#include <iostream>
#include <memory>
using namespace std;

class CMyData{
public:
    CMyData(){
        cout << "CMyData() 생성자" << endl;
    }
    ~CMyData(){
        cout << "CMyData() 소멸자" << endl;
    }
};

/*
int main(int argc, char *argv[]){
    auto_ptr<CMyData> ptrTest(new CMyData);
    auto_ptr<CMyData> ptrNew;

    cout << "0X" << ptrTest.get() << endl;
    ptrNew = ptrTest;

    cout << "0X" << ptrNew.get() << endl;
    cout << "0X" << ptrTest.get() << endl;
    return 0;
}
*/

class CTest{
public:
    CTest(){cout << "CTest 생성" << endl;}
    ~CTest(){cout << "Ctest 소멸" << endl;}
    void TestFunc(){cout << "func()" << endl;}
};
/*
int main(int argc, char *argv[]){
    shared_ptr<CTest> ptrTest(new CTest);
    cout << ptrTest.use_count() << endl;
    
    {
        shared_ptr<CTest> ptrNew(ptrTest);
        cout << ptrTest.use_count() << endl;
        ptrNew->TestFunc();
    }

    cout << ptrTest.use_count() << endl;
    return 0;
}
*/
/*
void RemoveTest(CTest *pTest){
    cout << "Romve" << endl;
    delete[] pTest;
}

int main(int argc, char *argv[]){
    shared_ptr<CTest> ptr1(new CTest[3], RemoveTest);//소멸자 지정
    return 0;
}
*/
int main(int argc, char* argv[]){
    unique_ptr<CTest> ptr1(new CTest);
    //unique_ptr(CTest) ptr2(ptr1);
    //ptr2 = ptr1;
    return 0;
}
