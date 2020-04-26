#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)return -1;
        int res = -1;
        vector<int> m(n, -1);
        for (auto x:nums){
            if (x<0 || x>=n){
                return -1;
            }
            if (m[x]==-1){
                m[x] = 1;
            }else{
                res = x;
            }
        }
        return res;
    }
};
int main(){
    int a, b;
    cin>> a;
    cin>> b;
    cout << a+b << endl;
}