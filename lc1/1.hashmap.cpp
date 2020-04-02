#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
    int n = nums.size();
    int i, j;
    vector<int> result;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++){
        if(map.find(nums[i])== map.end()){
            map[nums[i]]=i;
        }
        int another = target-nums[i];
        if(map.find(another)!=map.end() && map[another]!=i){
            result.push_back(map[another]);
            result.push_back(i);
            return result;
        }
    }
    return result;
}
int main(){
    vector<int> input={3,2,4};
    twoSum(input,6);
}