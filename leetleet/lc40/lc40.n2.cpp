class Solution {
public:
    int trap(vector<int>& height)
    {
        int ans = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            int max_left = 0;
            int max_right = 0;
            for (int j = 0; j <= i; j++) {
                max_left = max(height[j], max_left);
            }
            for (int j = i; j < n; j++) {
                max_right = max(height[j], max_right);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
};