#include <iostream>
using namespace std;

int main(int argc, char*argv[]){
    int n1, n2;
    cout << "두 숫자 입력: ";
    cin >> n1 >> n2;
    try{
        if(n2 == 0) throw n2;
        cout << "몫은 : " << n1 / n2 << endl;
        cout << "나머지는 : " << n1 % n2 << endl;
    }
    catch(int x){
        cout << x << "는 안된다 이놈아!" << endl;
        return -1;
    }
    return 0;
}
