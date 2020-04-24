#include "lib/general.h"
int removeDuplicates(vector<int>& nums)
{
    int slow = 0;
    int fast = 1;
    while (fast < nums.size()) {
        if (nums[slow] != nums[fast]) {
            slow++;
            nums[slow] = nums[fast];
        }
        fast++;
    }
    return slow + 1;
}

int main(){
    vector<int> input={0,0,1,1,1,2,2,3,3,4};
    cout << removeDuplicates(input) << endl;
}