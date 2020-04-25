#include "/home/neil/Codes/leetcode/lib/general.h"
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int a, b;
        a = b = 0;
        int n = s.size();
        int maxLength = 0;
        vector<int> m(128, -1);
        while (a < n && b < n) {
            if (m[s[b]] == -1 || m[s[b]] < a) {

            } else {
                a = m[s[b]] + 1;
            }
            m[s[b]] = b;
            b++;
            maxLength = max(maxLength, b - a);
        }
        maxLength = max(maxLength, b - a);
        return maxLength;
    }
};