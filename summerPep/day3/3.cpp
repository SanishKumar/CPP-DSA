#include <iostream>
using namespace std;

int main() {
    int num = 1;
    int arr[5][5] = {0};

    for(int row = 0; row < 5; row++) {
        for(int col = 0; col <= row; col++) {
            arr[row][col] = num++;
        }
    }

    for(int row = 0; row < 5; row++) {
            for(int col = row; col >= 0; col--) {
                cout << arr[row][col] << " ";
            }
        
        cout << endl;
    }
    return 0;
}