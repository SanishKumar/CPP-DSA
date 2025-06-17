#include <iostream>
using namespace std;

bool isPalindrome(int n){
    int num = 0;
    int num2 = n;
    while(n != 0){
        int rem = n % 10;
        num = num * 10 + rem;
        n = n / 10;
        // cout << num << endl; 
    }
    if(num == num2) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    if(isPalindrome(n)) cout << "Pal";
    else cout << "Not Pal";
}