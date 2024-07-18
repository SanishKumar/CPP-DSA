#include <iostream>
using namespace std;

int main(){
    int i=0, num=0, n;
    cin >> n;
    while(i<n){
        int j=0;
        while(j<i+1){
            cout << num+1 << " ";
            num++;
            j++;
        }i++;
        cout << endl;
    }
    return 0;
}
