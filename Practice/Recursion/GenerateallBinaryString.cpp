#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
        void solve(vector<string> &ans,string temp,int num){
            if(temp.size()==num){
                ans.push_back(temp);
                return;
            }
            if(temp.empty() || temp.back()=='0'){
                solve(ans,temp+"0",num);
                solve(ans,temp+"1",num);
            }
            if(temp.back()=='1')solve(ans,temp+"0",num);
        }
        vector<string> generateBinaryStrings(int num){
           vector<string> ans;
           solve(ans,"",num);
           return ans;
        }
    };