class Solution {
//https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/solution/mian-shi-ti-11-xuan-zhuan-shu-zu-de-zui-xiao-shu-3/
public:
    int minArray(vector<int>& numbers) {
        int n=numbers.size();
        if(n==0)return -1;
        if(n==1)return numbers[0];
        int i(0),j(n-1);
        while(i<j){
            int mid=(i+j)/2;
            if(numbers[mid]<numbers[j]){
                // target in [i, mid]
                j=mid;
            }else if(numbers[mid]>numbers[j]){
                // target in [mid+1, j]
                i=mid+1;
            }else{
                // cannot findout which interval
                // 缩小搜索范围
                j--;
            }
        }
        return numbers[i];
    }
};