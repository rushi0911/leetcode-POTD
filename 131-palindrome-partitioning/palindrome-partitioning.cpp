class Solution {
public:
    bool checkPal(string s,int l,int h){
        while(l < h){
            if(s[l] != s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    void solve(int idx,int n,string s,vector<string>temp,vector<vector<string>>&ans){
        if(idx  == n){
            ans.push_back(temp);
            return ;
        }
        for(int i=idx;i<n;i++){
            if(checkPal(s,idx,i)){
                temp.push_back(s.substr(idx,i-idx+1));
                solve(i+1,n,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,n,s,temp,ans);
        return ans;
    }
};