class Solution {
public: 
    void dfs(int i,int j,vector<vector<int>>&vis,int n,int m,vector<vector<char>>& grid){
        if(i<0 || i>=n) return ;
        if(j<0 || j>=m) return ;
        if(vis[i][j] == 1) return ;
        if(grid[i][j] == '0') return;
        if(grid[i][j] == '1') vis[i][j] = 1;
        dfs(i,j+1,vis,n,m,grid);
        dfs(i+1,j,vis,n,m,grid);
        dfs(i-1,j,vis,n,m,grid);
        dfs(i,j-1,vis,n,m,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    cnt++;
                    dfs(i,j,vis,n,m,grid);
                }
            }
        }
        return cnt;
    }
};