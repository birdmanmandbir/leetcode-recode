#include <vector>
using std::vector;
class Solution
{
public:
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> newBoard(m,vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = calculateAliveCells(board, i, j);
                if(count>3){
                    newBoard[i][j]=0;
                }else if(count==3){
                    newBoard[i][j]=1;
                }else if(count==2){
                    newBoard[i][j]=board[i][j];
                }else if(count<2){
                    newBoard[i][j]=0;
                }
            }
        }
        board=newBoard;
    }
    int calculateAliveCells(vector<vector<int>> &board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> directions = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {1, 1},
            {-1, -1},
            {-1, 1},
            {1, -1},
        };
        int count = 0;
        for (vector<int> v : directions)
        {
            int x = i + v[0];
            int y = j + v[1];
            if (x < 0 || y < 0 || x >= m || y >= n)
                continue;
            if (board[x][y])
                count++;
        }
        return count;
    }
};