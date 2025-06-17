#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    
    cin >> n;
    vector<int> arr;
    for(int i = 2; i < n; i++){
        if(isPrime(i)) arr.push_back(i);
    }

    for(int i : arr) cout << i << " ";

    return 1;
}