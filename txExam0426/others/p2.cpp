// 作者：MMMMMMMW
// 链接：https://www.nowcoder.com/discuss/417977
// 来源：牛客网

#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    ll x,y;
}a[100005],b[100005];
bool cmp(node q,node w){
    if (q.x == w.x) return q.y < w.y;
    return q.x < w.x;
}
int main(){
    int n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i = 0;i < n;i++)
            scanf("%lld%lld",&a[i].x,&a[i].y);
        for(int i = 0;i < n;i++)
            scanf("%lld%lld",&b[i].x,&b[i].y);

        sort(a,a+n,cmp);
        sort(b,b+n,cmp);

        double ans = -1;
        for(int i = 0;i < n;i++)
            for(int j = max(i-500,0);j < i+500 && j < n;j++){//原本过60%，取个范围，本来想防止超时混分，没想到直接AC
                double temp = pow(pow(a[i].x-b[j].x,2)+pow(a[i].y-b[j].y,2),0.5);
                if (ans < 0 || ans > temp)
                    ans = temp;
                // else break;
            }

        printf("%.3f\n", ans);
    }
    return 0;
}