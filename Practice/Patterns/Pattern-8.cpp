#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        int col1 = 1;
        while (col1 <= n - row + 1)
        {
            cout << col1;
            col1++;
        }

        for (int i = 0; i < 2*(row - 1); ++i)
        {
            std::cout << "*";
        }

        int col2 = n - row + 1;
        while (col2 > 0){
            cout << col2;
            col2--;
        }

        cout << endl;
        row++;
    }

    return 0;
}