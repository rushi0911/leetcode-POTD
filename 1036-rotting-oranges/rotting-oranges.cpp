class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
            }
        }
        // vis[0][0] = 1;
        int rc[] = {-1,1,0,0};
        int cc[] = {0,0,-1,1};
        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int temp_cnt = q.front().second;
            cnt = max(cnt,temp_cnt);
            q.pop();
            for(int k=0;k<4;k++){
                int nr = i+rc[k];
                int nc = j+cc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && vis[nr][nc]==-1){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},temp_cnt+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]== -1){
                    return -1;
                }
            }
        }
        return cnt;
    }
};