#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
    if(num == 2){
        return true;
    }
    for(int j = 2; j <= sqrt(num); j++){
        if(num%j==0){
            return false;
        }
    }
    return true;
}

int main(){
    int num = 5;

    if(isPrime(num)==true){
        cout<<"Prime";
    }else{
        cout << "Not Prime";
    }
    
}