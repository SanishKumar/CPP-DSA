#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> a(n), r(n);
        long long sum = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            sum += a[i];
        }
        // Read the radii; they are not used in computing the answer.
        for (int i = 0; i < n; i++){
            cin >> r[i];
        }
        
        // Maximum possible final value is sum(a) - (n - 1)
        cout << sum - (n - 1) << "\n";
    }
    return 0;
}
