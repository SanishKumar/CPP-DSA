// 344. Reverse String

class Solution {
public:
    void reverseString(std::vector<char>& s) {
        size_t start = 0;
        size_t end = s.size() - 1;

        while (start < end) {
            std::swap(s[start++], s[end--]);
        }
    }
};