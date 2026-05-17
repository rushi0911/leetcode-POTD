class Solution {
public:
    int res(int idx, int n, vector<int>&nums,vector<int>&dp){
        if(idx>=n) return 0;
        if(dp[idx] != -1) return dp[idx];
        int take = nums[idx] + res(idx+2,n,nums,dp);
        int noTake = res(idx+1,n,nums,dp);
        dp[idx]= max(take,noTake);
        return dp[idx];

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return res(0,n, nums, dp);
    }
};