#include <iostream>
using namespace std;

int main() {
    int a = 48, b = 18;
    int gcd = 1;
    int mn = (a < b) ? a : b;
    int mx = (a > b) ? a : b;

    for(int i = 1; i <= mn; i++) {
        if(mn % i == 0 && mx % i == 0) {
            if(i > gcd) gcd = i;
        }
    }

    int lcm = (a * b) / gcd;

    cout << "GCD: " << gcd << endl;
    cout << "LCM: " << lcm << endl;
    return 0;
}

// #include <iostream>
// using namespace std;

// int gcd(int a, int b) {
//     while(b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// int main() {
//     int a, b;
//     cin >> a >> b;
//     cout << "GCD: " << gcd(a, b) << endl;
//     return 0;
// }