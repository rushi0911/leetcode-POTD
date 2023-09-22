class Solution {
public:
    bool checkSeq(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i<0){
            return true;
        }
        if(j<0){
            return false;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // bool take = false;
        if(s[i]==t[j]){
            return dp[i][j]=checkSeq(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=checkSeq(i-1,j,s,t,dp) && checkSeq(i,j-1,s,t,dp);
    }

    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return checkSeq(n-1,m-1,s,t,dp);
    }
};