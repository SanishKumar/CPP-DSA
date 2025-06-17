#include <iostream>
using namespace std;

bool isStrongPassword(const string& password) {
    // if(password.length() < 8) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    // for(char ch : password) {
    //     if(ch >= 'a' && ch <= 'z') hasLower = true;
    //     else if(ch >= 'A' && ch <= 'Z') hasUpper = true;
    //     else if(ch >= '0' && ch <= '9') hasDigit = true;
    //     else hasSpecial = true;
    // }
    // return hasLower && hasUpper && hasDigit && hasSpecial;

    int len = 0;

    for(int i = 0; password[i] != '\0'; i++) {
        char ch = password[i];
        len++;
        if(ch >= 97 && ch <= 122) hasLower = true;         
        else if(ch >= 65 && ch <= 90) hasUpper = true;     
        else if(ch >= 48 && ch <= 57) hasDigit = true;     
        else hasSpecial = true;                            
    }
    if(len < 8) return false;
    return hasLower && hasUpper && hasDigit && hasSpecial;

}

int main() {
    string password;
    cin >> password;

    if(isStrongPassword(password))
        cout << "Strong password" << endl;
    else
        cout << "Weak password" << endl;
    return 0;
}


