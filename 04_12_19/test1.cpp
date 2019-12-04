#include <iostream>
using namespace std;

int StoI(const char * str){
    int temp = 0;
    if(str[0] == '0') throw '0';
    for(int i = 0; i < 100 && str[i] != '\0'; ++i){
        if('0' <= str[i] && str[i] <= '9'){
            temp *= 10;
            temp += str[i] - '0';
        }
        else{
            throw str[i];
        }
    }
    return temp;
}

int main(int argc, char * argv[]){
    char str1[100], str2[100];
    int n1, n2;

    cin >> str1 >> str2;

    try{
        n1 = StoI(str1);
        n2 = StoI(str2);
        cout << n1 + n2 << endl;
    }
    catch(char e){
        cout << e << "가 나옴" << endl;
    }
    return 0;
}
