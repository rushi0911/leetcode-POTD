class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>vec_idx;
        int n = mat.size();
        int m = mat[0].size();
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    cnt++;
                }else{
                    break;
                }
            }
            vec_idx.push_back(cnt);
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({vec_idx[i],i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};