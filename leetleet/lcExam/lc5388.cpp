#include "../lib/general.h"
class Solution {
public:
    string reformat(string s)
    {
        string charString;
        string intString;
        for (char c : s) {
            if (c <= '9' && c >= '0') {
                intString += c;
            } else {
                charString += c;
            }
        }
        string res;
        int m = charString.size();
        int n = intString.size();

        int i = 0, j = 0;
        if (m == n - 1 || n == m - 1 || m == n) {
            if (m <= n) {
                bool isInt = true;
                while (i < m || j < n) {
                    if (isInt) {
                        res += intString[j];
                        j++;
                    } else {
                        res += charString[i];
                        i++;
                    }
                    isInt = !isInt;
                }
            } else {
                bool isInt = false;
                while (i < m || j < n) {
                    if (isInt) {
                        res += intString[j];
                        j++;
                    } else {
                        res += charString[i];
                        i++;
                    }
                    isInt = !isInt;
                }
            }
            return res;
        } else {
            return "";
        }
    }
};

int main(){
    cout << (new Solution())->reformat("covid2019");
}