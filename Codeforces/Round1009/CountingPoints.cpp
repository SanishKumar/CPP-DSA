#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Function to count integer points inside or on a circle
ll count_points(int x, int r) {
    ll count = 0;
    for (int dx = -r; dx <= r; dx++) {
        int x_pos = x + dx;
        int max_y = sqrt(1LL * r * r - 1LL * dx * dx); // Compute max |y| for given x_pos
        count += 2 * max_y + 1;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> x(n), r(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> r[i];

        set<pair<int, int>> visited; // To avoid counting duplicate points
        ll total_points = 0;

        for (int i = 0; i < n; i++) {
            if (visited.count({x[i], r[i]})) continue;
            total_points += count_points(x[i], r[i]);
            visited.insert({x[i], r[i]});
        }

        cout << total_points << "\n";
    }

    return 0;
}
