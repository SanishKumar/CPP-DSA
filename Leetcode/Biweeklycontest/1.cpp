#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string findCommonResponse(vector<vector<string>>& responses) {
            unordered_map<string, int> freq;
    
            for(auto &day : responses){
                unordered_set<string> seen(day.begin(), day.end());
                for(auto &resp : seen){
                    ++freq[resp];
                }
            }
    
            int maxFreq = 0;
            string ans = "";
            for(auto &p : freq){
                const string &resp = p.first;
                int cnt = p.second;
                if(cnt > maxFreq || (cnt == maxFreq && resp < ans)){
                    maxFreq = cnt;
                    ans = resp;
                }
            }
            return ans;
        }
};

int main() {
    Solution solution;
    vector<vector<string>> responses = {
        {"good", "ok", "good", "ok"},
        {"ok", "bad", "good", "ok", "ok"},
        {"good"},
        {"bad"}
    };

    string result = solution.findCommonResponse(responses);
    cout << "Most common response: " << result << endl;

    return 0;
}