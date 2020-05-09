#include <bits/stdc++.h>
using namespace std;
/*
一种巧妙的思路是每次找到要remove部分就将后面的向前替换，使用j标记需要向前替换的位置
碰到AABB或者AAA则更新j

*/
string getCorrectString(string& s){
    int n = s.size();
    int j = 0;
    for (int i = 0; i < n; i++){
        s[j++] = s[i]; // 一开始不会改变字符串，仅当j改变时才会改变字符串
        if (j>=3 && s[j-3]==s[j-2] && s[j-2]==s[j-1]){
            // j 代表当前正确字符串的长度，所以要根据j去判断是否存在AABB和AAA; 角标j之前是合法的字符串
            j--; // 减1代表有一个字符需要remove
        }
        if (j>=4 && s[j-4]==s[j-3] && s[j-2]==s[j-1]){
            j--;
        }
    }
    s.erase(s.begin()+j, s.end());
    return s;
}

int main(){
    int N;
    cin >> N;
    string tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        cout << getCorrectString(tmp) << endl;
    }
}