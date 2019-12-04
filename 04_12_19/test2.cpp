#include <iostream>
using namespace std;

int* concat(int x[], int xSize, int y[], int ySize){
    int *result = new int[xSize + ySize];
    if(result == NULL)//메모리 부족
    {
        throw 1;
    }
    else if(x == NULL || y == NULL){
        throw 2;
    }
    else if(xSize <= 0 || ySize <= 0){
        throw 3;
    }
    for(int i = 0; i < xSize + ySize; ++i){
        if(i < xSize){
            result[i] = x[i];
        }
        else{
            result[i] = y[i - xSize];
        }
    }
    return result;
}

int main(){
    int x[] = {1,2,3,4,5};
    int y[] = {10,20,30,40};

    try{
        int* p = concat(x,0,y,4);
        for(int n = 0; n < 9; ++n){
            cout << p[n] << " ";
        }
            cout << endl;
            delete [] p;
    }
    catch(int failCode){
        cout << "오류 코드 : " << failCode << endl;
    }
    return 0;
}
