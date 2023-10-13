class Solution {
public:
    
    int minCost(int idx,int n,vector<int>&cost,vector<int>&dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int one = cost[idx]+minCost(idx+1,n,cost,dp);
        int two = cost[idx]+minCost(idx+2,n,cost,dp);
        return dp[idx]=min(one,two);
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(minCost(0,n,cost,dp),minCost(1,n,cost,dp));
    }
};