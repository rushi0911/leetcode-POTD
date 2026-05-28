class Solution {
public:
    int totalPath(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i >= n) return 0;
        if(j >= m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n-1 && j == m-1){
            if(grid[i][j] == 0) return 1;
            return 0;
        }
        if(grid[i][j] == 1) return 0;
        int down = totalPath(i+1,j,n,m,grid,dp);
        int right = totalPath(i,j+1,n,m,grid,dp);
        return dp[i][j] = down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return totalPath(0,0,n,m,obstacleGrid,dp);
    }
};