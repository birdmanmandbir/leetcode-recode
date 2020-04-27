#include <bits/stdc++.h>
using namespace std;

int myDepth(long x)
{
    return static_cast<int>((log(x) / log(2))) + 1;
}


long getResult(long x, int k)
{
    int md = myDepth(x);
    long tmp = x;
    if (md == k) {
        return -1;
    }
    for (int i = 0; i < md - k; i++) {
        tmp /= 2;
    }
    if (tmp > 0 && tmp != x) {
        return tmp;
    } else {
        return -1;
    }
}

int main()
{
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        long x;
        int k;
        cin >> x >> k;
        cout << getResult(x, k) << endl;
    }
}