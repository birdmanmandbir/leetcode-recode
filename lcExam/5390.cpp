#include "../lib/general.h"
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        vector<list<int>> states(5);
        int cnt = 1;
        int inProcess = 0;
        for (char c : croakOfFrogs) {
            switch (c) {
            case 'c':
                states[0].push_back(0);
                inProcess++;
                if (inProcess>cnt)cnt++;
                break;

            case 'r':
                if (!states[0].empty()) {
                    states[0].pop_back();
                    states[1].push_back(0);
                } else {
                    return -1;
                }
                break;

            case 'o':
                if (!states[1].empty()) {
                    states[1].pop_back();
                    states[2].push_back(0);
                } else {
                    return -1;
                }
                break;

            case 'a':
                if (!states[2].empty()) {
                    states[2].pop_back();
                    states[3].push_back(0);
                } else {
                    return -1;
                }
                break;

            case 'k':
                if (!states[3].empty()) {
                    states[3].pop_back();
                    inProcess--;
                } else {
                    return -1;
                }
                break;
            default:
                return -1;
            }
        }
        for (auto x:states){
            if (!x.empty()){
                return -1;
            }
        }
        return cnt;
    }
};

int main(){
    cout << (new Solution())->minNumberOfFrogs("crocakcroraoakk");
}