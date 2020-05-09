#include <bits/stdc++.h>
using namespace std;

bool Invalid(vector<int> &b, int n){
    for (int i = 0; i < n-1; i++){
        if (b[i]>b[i+1]){
            return false;
        }
    }
    return true;
}

int recur(vector<int> a, vector<int> b){
    int n = a.size();
    if (Invalid(a, n)){
        return -1;
    }
    int minCount = INT_MAX;
    for (int i = 0; i < n-1; i++){
        if (a[i]>a[i+1] && b[i]>b[i+1]){
            vector<int> aa(a);
            vector<int> bb(b);
            aa[i] = b[i+1];
            bb[i] = a[i+1];
            aa[i+1] = b[i];
            bb[i+1] = a[i];
            int res = recur(aa, bb);
            if (res==-1){
                continue;
            }else{

            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    if(Invalid(b, n)){
        cout << -1 << endl;
    }else{
        cout << 1 << endl;
    }
}