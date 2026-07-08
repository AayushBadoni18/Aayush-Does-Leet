class Solution {
public:
    int hehe(int i, int j, vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(i<0 || j<0)return 1e8;
        if(dp[i][j]!=-1)return dp[i][j];
        int up = grid[i][j]+hehe(i-1, j, dp , grid);
        int down = grid[i][j]+hehe(i, j-1, dp , grid);
        return dp[i][j] = min(up,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size(),vector<int>( grid[0].size(),-1));
        int ans = hehe(grid.size()-1, grid[0].size()-1, dp, grid);
        return ans;
    }
};