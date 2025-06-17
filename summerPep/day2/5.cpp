// Sieve of Eratosthenes

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) cout << i << " ";
    }
    cout << endl;
    return 0;
}