// Climb Stairs :

#include <iostream>
#include <vector>
    using namespace std;
void climbStairs(int n, vector<int> &ans)
{
    // base case
    if (n == 0)
    {
        for (int x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    // edge case
    if (n == -1)
    {
        return;
    }
    // one step down
    ans.push_back(1);
    climbStairs(n - 1, ans);
    ans.pop_back();
    // two step down
    ans.push_back(2);
    climbStairs(n - 2, ans);
    ans.pop_back();
}
int main()
{
    int n = 2;
    vector<int> ans;
    climbStairs(n, ans);
    return 0;
}
