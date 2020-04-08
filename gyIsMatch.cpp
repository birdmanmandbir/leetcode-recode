#include "lib/general.h"
bool isMatch(string pattern, string str)
{
    vector<string> v;
    const char* conStr = str.c_str();
    char* cstr = new char[str.size() + 1];
    strcpy(cstr, conStr);
    char* tmp = strtok(cstr, " ");
    while (tmp != NULL) {
        v.push_back(tmp);
        tmp = strtok(NULL, " ");
    }
    if (pattern.size() != v.size())
        return false;
    unordered_map<char, string> map;
    for (int i = 0; i < v.size(); i++) {
        char tmpc = pattern[i];
        string tmps = v[i];
        if (map.find(tmpc) == map.end()) {
            map[tmpc] = tmps;
        } else if (map[tmpc]!=tmps) {
            return false;
        }
    }
    return true;
}
int main(){
    string pat = "abba";
    string str = "dog cat cat fish";
    cout << isMatch(pat, str) << endl;
}