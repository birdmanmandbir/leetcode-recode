class Solution {
//https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
public:
    int minArray(vector<int>& numbers) {
        int n=numbers.size();
        if(n==0)return -1;
        if(n==1)return numbers[0];
        for(int i=1;i<n;i++){
            if(numbers[i-1]>numbers[i]){
                return numbers[i];
            }
        }
        return numbers[0];
    }
};