#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int row = 1;

    while(row <= n){
        int space = 2;
        while(space <= row){
            cout << " ";
            space = space + 1;
        }

        int col = n-row+1;
        while(col ){
            cout << "*";
            col = col - 1;
        }
        cout << endl;
        row = row + 1;
    }

    return 0;
}