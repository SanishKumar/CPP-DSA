#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = n * (n + 1) / 2;
    vector<vector<int>> a(n, vector<int>(n));
    int cur = 1;
    for (int d = 0; d < n; d++) {
        if (d % 2 == 0) {
            for (int i = d; i < n; i++) {
                a[i][i-d] = cur++;
            }
        } else {
            for (int i = n-1; i >= d; i--) {
                a[i][i-d] = cur++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << a[i][j] << (j==i ? "\n" : " ");
        }
    }
    return 0;
}
