#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k==0)return 1;
        mm=m;
        nn=n;
        kk=k;
        for(int i=0;i<m;i++){
            visited.push_back(vector<bool>(n, false));
        }
        return dfs(0,0,0,0);
    }
    int dfs(int i, int j, int si, int sj){
        if(i<0||i>=mm||j<0||j>=nn||(si+sj)>kk||visited[i][j])return 0;
        // 此处访问过就不用再走, 可以直接设为true
        visited[i][j]=true;
        // 机器人只需要走右或者下
        return 1+
            dfs(i+1,j,nextDigitalSum(i,si),sj)+
            dfs(i,j+1,si, nextDigitalSum(j,sj));

    }
    int nextDigitalSum(int number, int sn){
        return (number+1)%10==0? (sn-8) : sn+1;
    }
private:
    vector<vector<bool>> visited;
    int mm, nn, kk;
};

int main(){
    cout<<(new Solution())->movingCount(2,3,1)<<endl;
}