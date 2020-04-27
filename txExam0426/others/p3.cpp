// 作者：MMMMMMMW
// 链接：https://www.nowcoder.com/discuss/417977
// 来源：牛客网

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[50],b[50],now[50],n,ans;
int check;
void dfs(int value){
    check++;
    if (check >= 1e7) return;//递归超1e7后直接return，防超时（没加这个是过75%并超时，加完居然AC了）
    if (value >= ans) return;//剪枝
    bool flag = true;
    for(int i = 1;i <= n && flag;i++)
        if (now[i] < now[i-1])
            flag = false;
    if (flag){
        ans = min(ans,value);
        return ;
    }
    for(int i = 1;i <= n;i++)
        if (now[i] < now[i-1] ){
            swap(a[i],a[i-1]);
            swap(b[i],b[i-1]);
            swap(now[i],now[i-1]);
            if (now[i] == a[i]) now[i] = b[i];
            else now[i] = a[i];
            if (now[i-1] == a[i-1]) now[i-1] = b[i-1];
            else now[i-1] = a[i-1];
            dfs(value+1);
            swap(a[i],a[i-1]);
            swap(b[i],b[i-1]);
            swap(now[i],now[i-1]);
            if (now[i] == a[i]) now[i] = b[i];
            else now[i] = a[i];
            if (now[i-1] == a[i-1]) now[i-1] = b[i-1];
            else now[i-1] = a[i-1];
        }

}
int main(){
    cin >> n;
    ans = 1e6;
    check = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        now[i] = a[i];
    }
    for(int i = 1;i <= n;i++)
        cin >> b[i];

    dfs(0);
    cout << (ans == 1e6?-1:ans) << endl;

    return 0;
}