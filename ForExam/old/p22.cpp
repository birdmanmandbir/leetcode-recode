#include <bits/stdc++.h>
using namespace std;
// stfind 2
// 先递归左边，在递归右边？
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