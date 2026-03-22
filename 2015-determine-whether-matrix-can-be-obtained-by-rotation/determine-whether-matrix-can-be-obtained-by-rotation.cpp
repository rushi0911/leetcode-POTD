class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
       if(mat==target)
           return true;
        int n = mat.size();
        int m = mat[0].size();
        int k=3;
        while(k--){
            vector<vector<int>>temp(n,vector<int>(m,0));
            reverse(mat.begin(),mat.end());
            for(int j=0;j<m;j++){
                for(int i=0;i<n;i++){
                    temp[j][i]=mat[i][j];
                }
            }
            if(temp==target)
                return true;
            mat = temp;
        }
        // for(auto it:temp){
        //     for(auto x:it)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        return false;
    }
};