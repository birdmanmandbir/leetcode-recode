// 作者：MMMMMMMW
// 链接：https://www.nowcoder.com/discuss/417977
// 来源：牛客网
// 求节点x在满二叉树上第k层的祖先
#include <bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll num[70];
int main(){
    int q,len = 0;
    scanf("%d",&q);
    for(ll j = 1;j <= 2e18;len++,j<<=1){
        num[len] = j;
        // cout << j << endl;
    }

    // cout << num[len-1] << endl;
    while(q--){
        ll x;
        int k;
        cin >> x >> k;
        int i;
        for(i = 1;i < len;i++)
            if (x < num[i]) break;
        bool flag = true;
        // cout << len << ' ' <<i << endl;
        while(i){
            if (k > i || (k==i&&flag)){
                printf("-1\n");
                break;
            }
            else if (k == i) {
                printf("%lld\n", x);
                break;
            }
            else {
                x>>=1;
                flag = false;
            }
            i--;
        }
    }
    return 0;
}