#include <iostream>
#include <vector>
using namespace std;

int main(){
    string str;
    cin >> str;

    vector<char> vowels = {'a','e','i','o','u'};
    int count[5] = {0}; 

    for(char ch : str){
        for(int i = 0; i < 5; i++){
            if(ch == vowels[i]){
                count[i]++;
            }
        }
    }

    int totalVowels = 0;
    for(int i = 0; i < 5; i++){
        cout << vowels[i] << ": " << count[i] << endl;
        totalVowels += count[i];
    }
    cout << "Total vowels: " << totalVowels << endl;
}