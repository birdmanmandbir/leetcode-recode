// 作者：MMMMMMMW
// 链接：https://www.nowcoder.com/discuss/417977
// 来源：牛客网
// 双栈模拟队列
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    stack<int> a;
    stack<int> b;
    while(n--){
        char c[10];
        scanf("%s",c);
        if (c[0] == 'a'){
            int x;
            scanf("%d",&x);
            a.push(x);
        }
        else if (c[0] == 'p' && c[1] == 'e'){
            if (b.empty()){
                while(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
            }
            printf("%d\n", b.top());
        }
        else {
            if (b.empty()){
                while(!a.empty()){
                    b.push(a.top());
                    a.pop();
                }
            }
            b.pop();
        }
    }
    return 0;
}