// Sieve of Eratosthenes

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int cnt = 0;
    int n = 10;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            cnt++;
            for (int j = 2 * i; j < n; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }
    cout<<cnt;
}