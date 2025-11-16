class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            while(mp['0']){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
                if(mp['0']==0){
                    // cout<<i<<endl;
                }
            }
            if(mp['0']==0 && mp['1']){
                ans = (ans%1000000007 + (j-i+1)%1000000007)%1000000007;
                cout<<ans<<endl;
            }
            j++;
        }
        return ans%1000000007;
    }
};