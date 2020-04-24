// simple dfs; TLE
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S>1000||S<-1000)return 0;
        return dfs(nums, S, 0);
    }
    int dfs(vector<int>& nums, int S, int i){
        if(i==nums.size() && S==0)return 1;
        if(i>=nums.size())return 0;
        int count=0;
        count+=dfs(nums,S-nums[i],i+1);
        count+=dfs(nums,S+nums[i],i+1);
        return count;
    }
};