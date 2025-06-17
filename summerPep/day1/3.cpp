#include <iostream>
using namespace std;

int main(){
    string name;
    cin >> name;
    int cnt = 0;
    while (name[cnt] != '\0') {
        cout << name[cnt] << " ";
        cnt++;
    }
    cout << endl << cnt << endl;
    return 0;
}