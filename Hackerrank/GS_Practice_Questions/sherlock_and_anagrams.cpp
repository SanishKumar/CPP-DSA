// Two strings are anagrams of each other if the letters of one string can be rearranged to form the other string. Given a string, find the number of pairs of substrings of the string that are anagrams of each other.

// Example


// The list of all anagrammatic pairs is  at positions  respectively.

// Function Description

// Complete the function sherlockAndAnagrams in the editor below.

// sherlockAndAnagrams has the following parameter(s):

// string s: a string

// Returns

// int: the number of unordered anagrammatic pairs of substrings in 

// Input Format

// The first line contains an integer , the number of queries.
// Each of the next  lines contains a string  to analyze.

// Constraints



//  contains only lowercase letters in the range ascii[a-z].

// Sample Input 0

// 2
// abba
// abcd


// Sample Output 0

// 4
// 0


// Explanation 0

// The list of all anagrammatic pairs is  and  at positions  and  respectively.

// No anagrammatic pairs exist in the second query as no character repeats.

// Sample Input 1

// 2
// ifailuhkqq
// kkkk


// Sample Output 1

// 3
// 10


// Explanation 1

// For the first query, we have anagram pairs  and  at positions  and  respectively.

// For the second query:
// There are 6 anagrams of the form  at positions  and .
// There are 3 anagrams of the form  at positions  and .
// There is 1 anagram of the form  at position .

// Sample Input 2

// 1
// cdcd


// Sample Output 2

// 5


// Explanation 2

// There are two anagrammatic pairs of length :  and .
// There are three anagrammatic pairs of length :  at positions  respectively.



// #include <bits/stdc++.h>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>


using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {
    int count = 0;
    unordered_map<string, int> substrFreq;

    // Calculate frequencies of all substrings
    for (int i = 0; i < s.length(); i++) {
        for (int j = i; j < s.length(); j++) {
            string substr = s.substr(i, j - i + 1);
            sort(substr.begin(), substr.end());
            substrFreq[substr]++;
        }
    }

    // Count the number of anagram pairs
    for (auto& it : substrFreq) {
        int freq = it.second;
        // Number of pairs possible with 'freq' occurrences
        count += (freq * (freq - 1)) / 2;
    }

    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
