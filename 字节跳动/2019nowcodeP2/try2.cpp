#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
// Note that:
// @取余
// @排列组合
/*
当数字很大时（超过16），它的平方要大于它*2^4，所以此题要用long long
在64位系统中，int 4位，long 8位
*/
unsigned long C(unsigned long x)
{
    // 已经确定i处的值，在[j, i)区间中挑2个，所以是C（x,2）
    return (x * (x - 1) / 2);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int N, D;
    cin >> N >> D;
    unsigned long count = 0;
    vector<int> buildings(N);
    for (int i = 0, j = 0; i < N; i++) { // j 是区间起点
        cin >> buildings[i];
        while (i >= 2 && buildings[i]-buildings[j] > D){
            j++;
        }
        count += C(i-j);
        count %= 99997867;
    }
    cout << count % 99997867 << endl;
}