#include <iostream>
using namespace std;

int main()
{

    int ch;
    cout << "Choose: 1. Encrypt 2. Decrypt:"<< endl;
    cin >> ch;

    string str;
    cin >> str;

    string enc = "";

    if (ch == 1)
    {

        for (char i : str)
        {
            enc.push_back(i + 3);
        }
        cout << enc;
    }else{
        for (char i : str)
        {
            enc.push_back(i - 3);
        }
        cout << enc;
    }
    return 0;
}