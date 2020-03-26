#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
vector<int> a, b;
stack<int> st1, st2;

int main() {
    int n, x[100001];
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) cin >> x[i];

    for (int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        a.push_back(st1.size());
        b.push_back(st2.size());

        while (!st1.empty() && st1.top() <= x[i]) st1.pop();
        while (!st2.empty() && st2.top() <= x[j]) st2.pop();
        st1.push(x[i]);
        st2.push(x[j]);
    }
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; i++) cout << b[i] + a[i] + 1<< " ";
    return 0;
}