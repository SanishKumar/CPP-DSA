// 1422. Maximum Score After Splitting a String

#include <string>
class Solution {
public:
    int maxScore(string& s) {
        int n=s.size(); 
        int s_l=INT_MIN, c0=0, c1=0;
        for(int i=0; i<n-1; i++){
            if (s[i]=='0') c0++;
            else c1++;
            s_l=max(s_l, c0-c1);
        }
        c1+=(s[n-1]=='1');
        return s_l+c1;
    }
};