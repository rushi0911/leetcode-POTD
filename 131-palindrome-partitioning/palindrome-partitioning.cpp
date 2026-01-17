class Solution {
public:
    bool checkPal(string s,int l,int h){
        while(l <= h){
            if(s[l] != s[h]){
                return false;
            }
            l++;
            h--;
        }
        return true;
    }
    void solve(int idx,int n,string s,vector<vector<string>>&ans,vector<string>str){
        if(idx == n){
            ans.push_back(str);
            return ;
        }
        for(int i=idx;i<n;i++){
            if(checkPal(s,idx,i)){
                string temp = s.substr(idx,i-idx+1);
                str.push_back(temp);
                solve(i+1,n,s,ans,str);
                str.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>str;
        solve(0,n,s,ans,str);
        return ans;
    }
};