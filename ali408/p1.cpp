// 第一题
// 某人有n次机会攻击m个怪兽。攻击时，可以一次攻击b只怪兽。每个怪兽有a滴血，每次攻击能让b只怪兽都减一。给定nmab后，最多能消灭多少只怪兽
    // 贪心即可，和电池使用问题类似
// 作者：小饭勺
// 链接：https://www.nowcoder.com/discuss/404810?type=all&order=time&pos=&page=1
// 来源：牛客网


// 解析
// 如果b > m, 一次只能攻击m个怪兽, 如果n >= a, 显然可以干掉m个怪兽
#include <iostream>
using namespace std;
int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if(b>m){
        cout<< (n >=a? m:0);
    }else{
        int res=n*b/a;
        cout<< (res > m? m:res);
    }
}