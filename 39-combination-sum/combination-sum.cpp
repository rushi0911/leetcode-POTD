class Solution {
public:
    void solve(int idx,int n,vector<int>& candidates,vector<int>& temp,vector<vector<int>>&ans, int target){
        if(target == 0){
                ans.push_back(temp);
                return;
            }
        if(idx == n){
            
            return ;
        }
        if(target >= candidates[idx]){
            temp.push_back(candidates[idx]);
            solve(idx,n,candidates,temp,ans,target-candidates[idx]);
            temp.pop_back();
        }
        solve(idx+1,n,candidates,temp,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,candidates,temp,ans,target);
        return ans;
    }
};