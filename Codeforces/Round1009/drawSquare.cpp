#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int l, r, d, u;
        cin >> l >> r >> d >> u;
        
        if(l == r && d == u)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
    return 0;
}
