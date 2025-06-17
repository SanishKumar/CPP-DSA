#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    getline(cin, str); 

    vector<string> words;
    string word = "";

    for(char ch : str){
        if(ch == ' '){
            if(!word.empty()){
                words.push_back(word);
                word = "";
            }
        } else {
            word += ch;
        }
    }
    if(!word.empty()) words.push_back(word);

    for(int i = words.size() - 1; i >= 0; i--){
        cout << words[i];
        if(i != 0) cout << " ";
    }
    cout << endl;
}