#include "../lib/general.h"
// https://leetcode-cn.com/problems/hand-of-straights/solution/ni-men-ke-neng-bu-zhi-dao-zhi-yong-20-mo-ying-dao-/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n%W != 0)return false;
        map<int, int> count;
        for (auto x:hand){
            count[x]++;
        }
        while (count.size()){
            int start = count.begin()->first;
            for (int i = start; i<start+W;++i){
                if (count.find(i) == count.end())return false;
                if (!--count[i]){
                    count.erase(i);
                }
            }
        }
        return true;
    }
};