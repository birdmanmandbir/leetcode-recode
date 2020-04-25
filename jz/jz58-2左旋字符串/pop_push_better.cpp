#include "/home/neil/Codes/leetcode/lib/general.h"
// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/solution/c-zhong-gui-zhong-ju-de-4msjie-fa-by-gary_coding/
// 4ms 效率比原来高很多， 因为大大减少了string的扩容和复制
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return (s+s).substr(n, s.size());
    }

};

int main(){
    (new Solution())->reverseLeftWords("absdad", 2);
}