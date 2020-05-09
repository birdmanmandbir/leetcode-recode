// 作者：MMMMMMMW
// 链接：https://www.nowcoder.com/discuss/417977
// 来源：牛客网
// 模拟队列
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int que[200005];
int main(){
    int t;
    cin >> t;
    while(t--){
        int q;
        int len = 0,now = 0,back = 0;
        cin >> q;
        while(q--){
            char a[10];
            int x;
            cin >> a;
            if (a[0] == 'P' && a[1] == 'U'){
                cin >> x;
                que[back++] = x;
                len++;
            }
            else if (a[0] == 'T'){
                if (len == 0) cout << -1 << endl;
                else cout << que[now] << endl;
            }
            else if (a[0] == 'P'){
                if (now == back) cout << -1 << endl;
                else {
                    now++;
                    len--;
                }
            }
            else if (a[0] == 'S'){
                cout << len << endl;
            }
            else {
                len = now = back = 0;
            }
        }
    }
    return 0;
}