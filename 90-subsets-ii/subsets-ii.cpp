class Solution {
public:
    void solve(int idx, int n, vector<int>& nums,vector<int>&temp, vector<vector<int>>&ans){
        ans.push_back(temp);
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,n,nums,temp,ans);
        return ans;
    }
};