#include <cstdio>
using namespace std;

const int maxn=int(1e6)+11;
int n;
int a[maxn];

void solve(int l,int r,int mark) {
    if(l==r) {
        if(mark) a[l]=1;
        else a[l]=2;
        return;
    }
    int mid=(l+r)>>1;
    solve(l,mid,1), solve(mid+1,r,0);
    for(int i=l;i<=r;++i)
        a[i]=a[i]*2-mark;
    return;
}

int main() {
    scanf("%d",&n);
    solve(1,n,0);

    int i;
    for(i=1;i<=n;++i) printf("%d ",a[i]/2);
    putchar('\n');

    return 0;
}
// ————————————————
// 版权声明：本文为CSDN博主「yashem66」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
// 原文链接：https://blog.csdn.net/qq_33330876/java/article/details/105574020