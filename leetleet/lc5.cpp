#include "lib/general.h"
class Solution {
public:
    string longestPalindrome(string s)
    {
        if (s.size() == 0) {
            return "";
        }
        int start(0), end(0);
        for (int i = 0; i < s.size(); i++) {
            int length = max(expandAroundCenter(s, i, i),
                expandAroundCenter(s, i, i + 1));
            if (length > end - start + 1){
                start = i - (length - 1)/2;
                end = i + length/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    /**
     * return: length of result string
     *
     **/
    int expandAroundCenter(const string& s, int left, int right)
    {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};