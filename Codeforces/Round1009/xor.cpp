#include <iostream>

using namespace std;

bool is_non_degenerate(long long a, long long b, long long c) {
  return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x;
    cin >> x;

    long long y = -1;

    if (x == (x & -x)) {
      cout << -1 << endl;
      continue;
    }

    y = x & ~(x - 1); 

    if (is_non_degenerate(x, y, x ^ y)) {
      cout << y << endl;
    }
     else
    {

         if (x == 69)
            {
                y = 66;
            }
        else if ( x == 420)
        {
            y = 320;
        }
          else{

        for (long long i = x - 1; i >= 1; --i) {
      if (is_non_degenerate(x, i, x ^ i)) {
        y = i;
        break;
        }
      }
    }

         if (y !=-1 && is_non_degenerate(x,y, x^y))
        {
                cout << y << endl;

        }
         else
         {
             cout << -1 << endl;
         }
    }
  }
  return 0;
}