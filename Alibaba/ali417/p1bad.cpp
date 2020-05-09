#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int>&, vector<int>&);
vector<int> divide(vector<int>& arr, int i, int j)
{
    if ((j - i + 1) <= 3 && (j - i + 1) > 1) {
        swap(arr[j], arr[j - 1]);
        vector<int> res;
        for (int a = i; a <= j; a++) {
            res.push_back(arr[a]);
        }
        return res;
    } else if ((j - i + 1) == 1) {
        return vector<int>(1, arr[i]);
    }
    vector<int> left = divide(arr, i, (i + j) / 2);
    vector<int> right = divide(arr, (i + j) / 2 + 1, j);
    return merge(left, right);
}

vector<int> merge(vector<int>& arr1, vector<int>& arr2)
{
    int m = arr1.size();
    int n = arr2.size();
    vector<int> res(m + n);
    int i, j, k;
    i = j = k = 0;
    bool first = true;
    for (; k < m + n; k++) {
        if (i <= m && j <= n) {
            if (first) {
                res[k] = arr1[i];
                i++;
                first = false;
            } else {
                res[k] = arr2[j];
                j++;
                first = true;
            }
        } else if (i <= m) {
            res[k] = arr1[i];
            i++;
        } else if (j <= n) {
            res[k] = arr2[j];
            j++;
        }
    }
    return res;
}

bool doTest(int n)
{
    vector<int> src(n);
    for (int i = 0; i < n; i++) {
        src[i] = i + 1;
    }
    vector<int> res = divide(src, 0, n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (res[i] +res[k]==2*res[j]){
                    return false;
                }
            }
        }
    }
    return true;
}

bool doTestFake(int n)
{
    vector<int> res = {1, 2 ,3};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (res[i] +res[k]==2*res[j]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    // input
    int n;
    cin >> n;
    // similar to merge sort
    vector<int> src(n);
    for (int i = 0; i < n; i++) {
        src[i] = i + 1;
    }
    vector<int> res = divide(src, 0, n - 1);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;



    // for (int i=1;i<n+1;i++){
    //     if (!doTest(i)){
    //         cout << i <<endl;
    //     }
    // }

}