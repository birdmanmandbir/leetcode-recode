#include "/home/neil/Codes/leetcode/lib/general.h"

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        for (int i=0;i<n;i++){
            char tmp = pop(s);
            push(s, tmp);
        }
        return s;
    }
    char pop(string &s){
        char res = s[0];
        s = s.substr(1, s.size()-1);
        return res;
    }
    void push(string &s, char c){
        s+=c;
    }
};