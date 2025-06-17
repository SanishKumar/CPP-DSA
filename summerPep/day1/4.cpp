#include <iostream>
using namespace std;

void lower(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

void upper(string &str){
    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

int main(){
    string str;
    cin >> str;

    string lowerStr = str;
    string upperStr = str;

    lower(lowerStr);
    upper(upperStr);

    cout << "Lowercase: " << lowerStr << endl;
    cout << "Uppercase: " << upperStr << endl;
}