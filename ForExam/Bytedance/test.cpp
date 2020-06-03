#include <bits/stdc++.h>
using namespace std;
#define BIG_NUM 835672545
long long res = 0;
string article;
vector<string> dict;
vector<bool> dp;
// ioa: 在i处之前已经保证可以被字典分开

int main(){
    std::ios::sync_with_stdio(false);
    string s = "abcade";
    string d = "de";
    cout << &s+5 << endl;
    cout << memcmp((char *)&s+4, (char *)&d, d.size()) << endl;
}