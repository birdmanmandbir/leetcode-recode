#include "/home/neil/Codes/leetcode/lib/general.h"
class Solution {
public:
    int sumNums(int n) {
        if (n==0) return 0;
        return n+sumNums(n-1);
    }
};