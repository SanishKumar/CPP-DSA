#include <iostream>
using namespace std; 

bool checkbits(int n, int i){
    return n&(1<<i);
}

int main(){
    int num = 30;
    int count = 0;
    for(int i = 0; i < 5; i++){
        if(checkbits(num, i)){
            count++;
        }
    }
    cout << count;
}