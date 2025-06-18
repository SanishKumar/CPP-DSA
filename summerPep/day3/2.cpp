#include <iostream>
using namespace std;

int main() {
    int arr[5][5] = {0};
    int num = 1;
    for(int j = 0; j < 5; j++) {
        for(int i = 0; i < 5 - j; i++) {
            arr[i][j] = num++;
        }
    }
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5 - i; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}