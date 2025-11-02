class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(auto it:walls){
            vis[it[0]][it[1]] = 2;
        }
        for(auto it:guards){
            vis[it[0]][it[1]] = 1;
        }
        int cnt_g = 0;
        for(auto it : guards){
            int row = it[0];
            int col = it[1];
    
            // upward row
            for(int i=row-1;i>=0;i--){
                if(vis[i][col] == 2 || vis[i][col] == 1){
                    break;
                }else{
                    vis[i][col] = -1;
                }
            }
            // down row
            for(int i=row+1;i<n;i++){
                if(vis[i][col] == 2 || vis[i][col] == 1){
                    break;
                }else{
                    vis[i][col] = -1;
                }
            }
            // right col
            for(int j=col+1;j<m;j++){
                if(vis[row][j] == 2 || vis[row][j] == 1){
                    break;
                }else{
                    vis[row][j] = -1;
                }
            }
            // right col
            for(int j=col-1;j>=0;j--){
                if(vis[row][j] == 2 || vis[row][j] == 1){
                    break;
                }else{
                    vis[row][j] = -1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0){
                    cnt++;
                }
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        return cnt;
    }
};