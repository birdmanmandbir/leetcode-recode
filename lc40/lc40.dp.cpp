#include <math.h>
#include <vector>
using std::vector;
int trap(vector<int>& height)
{
    int ans = 0;
    int n = height.size();
    vector<int> maxLeft(n, -1);
    vector<int> maxRight(n, -1);
    for (int i = 0; i < n; i++) {
        maxLeft[i] = i == 0 ? height[i] : max(maxLeft[i - 1], height[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        maxRight[i] = i == n - 1 ? height[i] : max(maxRight[i + 1], height[i]);
    }
    for (int i = 0; i < n; i++) {
        ans += min(maxLeft[i], maxRight[i]) - height[i];
    }

    return ans;
}
