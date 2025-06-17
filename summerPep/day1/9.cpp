#include <iostream>
using namespace std;

// void retrun(int n){
//     if (n==4) return;
//     if(n > 2) cout << "G" << endl;
//     else cout << "L" << endl;
//     retrun(n+1);
// }

int main(){
    int n = 2;
    // retrun(n);
    if(++n == 2) cout << "G" << endl;
    else cout << "L" << endl;
    return 0;
}