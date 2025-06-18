#include <iostream>
using namespace std;

int main() {
    int num = 1;
    for(int i = 5; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
    return 0;
}