class Solution {
public:
    void solve(int idx,int n,vector<int>& candidates,vector<int>& temp,vector<vector<int>>&ans, int target){
        if(target == 0){
            ans.push_back(temp);
            return ;
        }
        for(int i = idx;i<candidates.size();i++){
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(target >= candidates[i]){
                temp.push_back(candidates[i]);
                solve(i+1,n,candidates,temp,ans,target-candidates[i]);
                temp.pop_back();
            }
        }
        
        // solve(idx+1,n,candidates,temp,ans,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        solve(0,n,candidates,temp,ans,target);
        return ans;
    }
};