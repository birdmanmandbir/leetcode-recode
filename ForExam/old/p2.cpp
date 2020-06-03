#include <bits/stdc++.h>
using namespace std;
// 应该这样做：  扫k次，每次从高位开始如果比后一个字母大就去掉这个字母
// 字典序就是从左往右，所以不需要考虑从右往左
int main()
{
    string input;
    int k;
    cin >> input >> k;
    int n = input.size();
    set<int> st;
    for (int i = 0; i < n - 1; i++) {
        if (input[i] > input[i + 1] && k > 0) {
            st.insert(i);
            k--;
        } else if (input[i] == input[i + 1] && k > 0) {
            int j = i + 1;
            while (j < n && input[i] == input[j] && k > 0)
                j++;
            if (j < n && input[i] > input[j] && k > 0) {
                st.insert(i);
                k--;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (input[i] > input[i + 1] && k > 0 && st.find(i) == st.end()) {
            st.insert(i);
            k--;
        } else if (input[i] == input[i + 1] && k > 0 && st.find(i) == st.end() || (k > 0 && st.find(i + 1) != st.end() && st.find(i) == st.end())) {
            int j = i + 1;
            while (j < n && input[i] == input[j] || (j >= 0 && st.find(j) != st.end()))
                j++;
            if (j < n && input[i] > input[j] && k > 0) {
                st.insert(i);
                k--;
            }
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (input[i] > input[i - 1] && k > 0 && st.find(i) == st.end()) {
            st.insert(i);
            k--;
        } else if ((input[i] == input[i - 1] && k > 0 && st.find(i) == st.end()) || (k > 0 && st.find(i - 1) != st.end() && st.find(i) == st.end())) {
            int j = i - 1;
            while ((j >= 0 && input[i] == input[j]) || (j >= 0 && st.find(j) != st.end()))
                j--;
            if (j >= 0 && input[i] > input[j] && k > 0) {
                st.insert(i);
                k--;
            }
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (input[i] > input[i - 1] && k > 0 && st.find(i) == st.end()) {
            st.insert(i);
            k--;
        } else if ((input[i] == input[i - 1] && k > 0 && st.find(i) == st.end()) || (k > 0 && st.find(i - 1) != st.end() && st.find(i) == st.end())) {
            int j = i - 1;
            while ((j >= 0 && input[i] == input[j]) || (j >= 0 && st.find(j) != st.end()))
                j--;
            if (j >= 0 && input[i] > input[j] && k > 0) {
                st.insert(i);
                k--;
            }
        }
    }
    // for (int i = 0; i < n - 1; i++) {
    //     if (input[i] > input[i + 1] && k > 0 && st.find(i) == st.end()) {
    //         st.insert(i);
    //         k--;
    //     } else if (input[i] == input[i + 1] && k > 0 && st.find(i) == st.end() || (k > 0 && st.find(i + 1) != st.end() && st.find(i) == st.end())) {
    //         int j = i + 1;
    //         while (j < n && input[i] == input[j] || (j >= 0 && st.find(j) != st.end()))
    //             j++;
    //         if (j < n && input[i] > input[j] && k > 0) {
    //             st.insert(i);
    //             k--;
    //         }
    //     }
    // }
    int i = 0;
    while (k > 0 && i < n) {
        if (st.find(i) != st.end()) {
            i++;
        } else {
            st.insert(i);
            k--;
        }
    }
    for (int i = 0; i < n; i++) {
        if (st.find(i) != st.end()) {
        } else {
            cout << input[i];
        }
    }
    cout << endl;
}