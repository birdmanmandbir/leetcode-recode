#include <iostream>
#include <vector>
using namespace std;
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
    int k = isEven ? (m + n) / 2 : (m + n) / 2 + 1;
    int kd2 = k / 2;
    int i = 0;
    int j = 0;
    for (; k > 1 && !iOut && !jOut; k = k - kd2, kd2 = k / 2) {
        int a = nums1[min(i + kd2 - 1, m - 1)];
        int b = nums2[min(j + kd2 - 1, n - 1)];
        if (a <= b) {
            int previ = i;
            i = min(i + kd2, m - 1);
            // 超过末尾
            if (previ == i) {
                iOut = true;
            }
        } else {
            int prevj = j;
            j = min(j + kd2, n - 1);
            if (prevj == j) {
                jOut = true;
            }
        }
    }
    if (iOut) {
        if (isEven) {
            return (nums2[j + k - 1] + nums2[j + k]) / 2.0;
        } else {
            return nums2[j + k - 1];
        }
    } else if (jOut) {
        if (isEven) {
            return (nums1[i + k - 1] + nums1[i + k]) / 2.0;
        } else {
            return nums1[i + k - 1];
        }
    }
    if (isEven) {
        int a = min(nums1[i], nums2[j]);
        int b = 0;
        if (a == nums1[i]) {
            i++;
            if (i >= m) {
                iOut = true;
            }
            b = iOut ? nums2[j] : min(nums1[i], nums2[j]);
        } else {
            j++;
            if (j >= n) {
                jOut = true;
            }
            b = jOut ? nums1[i] : min(nums1[i], nums2[j]);
        }
        return (a + b) / 2.0;
    } else {
        return min(nums1[i], nums2[j]);
    }
}
int main()
{
    // vector<int> a = { 1, 3, 4, 8 };
    // vector<int> b = { 1, 2, 5, 7 };
    // vector<int> a = { 1, 3, 4 };
    // vector<int> b = { 1, 2, 5, 7 };
    // vector<int> a = { 1, 2 };
    // vector<int> b = { 3, 4 };
    vector<int> a = { 1 };
    vector<int> b = { 2, 3, 4, 5, 6, 7 };

    cout << findMedianSortedArrays(a, b) << endl;
}