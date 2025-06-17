#include <iostream>
using namespace std;

bool isValidIP(string ip) {
    int num = 0, dots = 0, len = 0;
    for(int i = 0; ip[i] != '\0'; i++) len++;

    int i = 0;
    while(i < len) {
        num = 0;
        int cnt = 0;
        if(ip[i] == '.') return false;
        while(i < len && ip[i] != '.') {
            if(ip[i] < '0' || ip[i] > '9') return false;
            num = num * 10 + (ip[i] - '0');
            cnt++;
            if(cnt > 3) return false; 
            i++;
        }
        if(cnt == 0 || num < 0 || num > 255) return false;
        dots++;
        i++; 
    }
    return dots == 4 && ip[len-1] != '.';
}

int main() {
    string ip;
    cin >> ip;
    if(isValidIP(ip))
        cout << "Valid IP address" << endl;
    else
        cout << "Invalid IP address" << endl;
}