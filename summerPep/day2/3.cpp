#include <iostream>
using namespace std;

bool isPalindrome(string &str) {
    int i = 0, j = 0;
    while(str[j] != '\0') j++; 
    j--; 
    while(i < j) {
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
}

void makePalindrome(string &str) {
    int len = 0;
    while(str[len] != '\0') len++; 
    int i = 0, j = len - 1;
    while(i < j) {
        if(str[i] != str[j]) {
            for(int k = j; k >= i; k--) {
                str += str[k];
            }
            break;
        }
        i++;
        j--;
    }
}

int main() {
    string str;
    cin >> str;

    if(isPalindrome(str)) {
        cout << "Already a palindrome: " << str << endl;
    } else {
        makePalindrome(str);
        cout << "Palindrome string: " << str << endl;
    }
    return 0;
}