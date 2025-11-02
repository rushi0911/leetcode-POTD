class Solution {
public:
    void solveF(int i, int j, int n, int m, vector<vector<int>>&vis, vector<vector<int>>& g, vector<vector<int>>& w,int dir,vector<vector<int>> &dp){
        if(i<0 || i>=n ){
            return ;
        }
        if(j<0 || j>=m){
            return ;
        }
        // if(dp[i][j] != -1) return ;
        if(vis[i][j] == 0 || vis[i][j]==1){
            return ;
        }
        if(dp[i][j] == dir){
            return ;
        }
        vis[i][j] = 2;
        dp[i][j] = dir;
        if(dir == 1)solveF(i+1,j,n,m,vis,g,w,1,dp);
        if(dir == 2)solveF(i-1,j,n,m,vis,g,w,2,dp);
        if(dir == 3)solveF(i,j+1,n,m,vis,g,w,3,dp);
        if(dir == 4)solveF(i,j-1,n,m,vis,g,w,4,dp);
        return ;
    }
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(n,vector<int>(m,-1));
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(auto it:walls){
            vis[it[0]][it[1]] = 0;
            // dp[it[0]][it[1]] = 0;
        }
        for(auto it : guards){
            vis[it[0]][it[1]] = 1;
            solveF(it[0]+1,it[1],n,m,vis,guards,walls,1,dp);
            solveF(it[0]-1,it[1],n,m,vis,guards,walls,2,dp);
            solveF(it[0],it[1]+1,n,m,vis,guards,walls,3,dp);
            solveF(it[0],it[1]-1,n,m,vis,guards,walls,4,dp);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == -1){
                    cnt++;
                }
                // cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        return cnt;
    }
};