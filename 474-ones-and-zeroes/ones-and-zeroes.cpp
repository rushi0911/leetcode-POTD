class Solution {
public:
    int fun(int idx,vector<pair<int,int>>&vec,int m,int n,int sum0,int sum1,vector<vector<vector<int>>>&dp){
        if(sum0 > m || sum1 > n){
            return -1e9;
        }
        if(idx == vec.size()){
            if(sum0 <= m && sum1 <= n){
                return 0;
            }
            return -1e9;
        }
        if(dp[idx][sum0][sum1] != -1){
            return dp[idx][sum0][sum1];
        }
        int temp0 = sum0 + vec[idx].first;
        int temp1 = sum1 + vec[idx].second;
        int take = 1 + fun(idx+1,vec,m,n,temp0,temp1,dp);
        int nottake = fun(idx+1,vec,m,n,sum0,sum1,dp);
        return dp[idx][sum0][sum1] = max(take,nottake);


    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int n1 = strs.size();
        vector<pair<int,int>>vec;
        for(auto it: strs){
            int cnt0 = count(it.begin(),it.end(),'0');
            int cnt1 = count(it.begin(),it.end(),'1');
            vec.push_back({cnt0,cnt1});
        }
        for(auto it:vec){
            cout<<it.first<<" "<<it.second<<endl;
        }
        int sum0=0 ,sum1=0;
        vector<vector<vector<int>>>dp(n1+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        int ans = fun(0,vec,m,n,sum0,sum1,dp);
        return ans;
    }
};