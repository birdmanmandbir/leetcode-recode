#include "lib/general.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int cur = matrix[mid / n][mid % n];
            if (cur < target) {
                left = mid + 1;
            } else if (cur > target) {
                right = mid - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};