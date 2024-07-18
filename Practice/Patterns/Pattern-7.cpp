#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int row = 1;

    while (row <= n)
    {
        int space = n - row;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }

        int col = 1;
        while (col <= row)
        {
            cout << col;
            col++;
        }

        int col2 = row - 1;
        while (col2){
            cout << col2;
            col2--;
        }

        cout << endl;
        row++;
    }

    return 0;
}