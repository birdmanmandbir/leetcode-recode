#include <stack>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    // 不需要visit数组, 因为可以让已经访问的小岛"下沉"
    void dfs(vector<vector<char>>& grid, int x, int y){
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> operators={
            {0,-1},
            {0,1},
            {1,0},
            {-1,0}

        };
        stack<pair<int,int>> curNeighbors;
        // depth first search
        curNeighbors.push({x,y});
        while(!curNeighbors.empty()){
            auto cur=curNeighbors.top();
            // 防止后面的点再将这个点push进stack
            grid[cur.first][cur.second]='0';
            bool findIt=false;
            for(vector<int> o:operators){
                pair<int,int> pos={cur.first+o[0],cur.second+o[1]};
                if(pos.first>=m || pos.first<0 ||
                    pos.second>=n || pos.second<0
                ){
                    continue;
                }
                if(grid[pos.first][pos.second]=='1'){
                    curNeighbors.push(pos);
                    findIt=true;
                    break;
                }
            }
            if(findIt){continue;}
            curNeighbors.pop();
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(m==0)return -1;
        int n=grid[0].size();
        int countIslands=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    // new island
                    ++countIslands;
                    dfs(grid, i, j);
                }
            }
        }
        return countIslands;
    }
};

int main(){
    vector<vector<char>> grid={
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout<<(new Solution())->numIslands(grid)<<endl;
}