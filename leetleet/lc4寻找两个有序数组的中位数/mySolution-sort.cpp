#include "/home/neil/Codes/leetcode/lib/general.h"
// 使用了排序，所以是nlogn， n = m + n
void printVector(vector<int>& v)
{
    for (auto x : v) {
        cout << x << "->";
    }
    cout << endl;
}
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    bool iOut = false;
    bool jOut = false;
    if (m == 0 && n != 0)
        iOut = true;
    if (n == 0 && m != 0)
        jOut = true;
    bool isEven = (m + n) % 2 == 0;
    // 如果是奇数, 就取第(m + n)/2+1个,如果是偶数, 就取 (m + n) / 2 和 (m + n) / 2 + 1 个然后/2
    vector<int> c(m + n);
    copy(nums1.begin(), nums1.begin() + m, c.begin());
    copy(nums2.begin(), nums2.begin() + n, c.begin() + m);
    sort(c.begin(), c.end());
    return isEven ? (c[(m + n) / 2 - 1] + c[(m + n) / 2 + 1 - 1]) / 2.0 : c[(m + n) / 2 + 1 - 1];
}

int main()
{
    // vector<int> a = { 1, 3, 4, 8 };
    // vector<int> b = { 1, 2, 5, 7 };
    // vector<int> a = { 1, 3, 4 };
    // vector<int> b = { 1, 2, 5, 7 };
    vector<int> a = { 1, 2 };
    vector<int> b = { 3, 4 };
    // vector<int> a = { 1 };
    // vector<int> b = { 2, 3, 4, 5, 6, 7 };

    cout << findMedianSortedArrays(a, b) << endl;
}