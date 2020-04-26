#include "lib/general.h"
class Solution {
public:
    string countAndSay(int n)
    {
        string result = "1";
        for (int i = 1; i < n; i++) {
            result = nextString(result);
        }
        return result;
    }
    string nextString(string s)
    {
        string result = "";
        int num = 1;
        for (int i = 0; i < s.size() - 1; i++){
            if (s[i]==s[i+1]){
                num++;
            }else{
                result += to_string(num);
                result += s[i];
                num = 1;
            }
        }
        result += to_string(num);
        result += s[s.size()-1];
        return result;
    }
};