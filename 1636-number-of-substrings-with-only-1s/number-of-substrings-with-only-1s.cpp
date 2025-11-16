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
            }
            // cout<<"i->"<<i<<endl;
            // cout<<"j->"<<j<<endl;
                ans = (ans%1000000007 + (j-i+1)%1000000007)%1000000007;
            // if(mp['1']){
            //     cout<<j<<endl;
            //     cout<<"i->"<<i<<endl;
            //     // cout<<ans<<endl;
            // }
            j++;
        }
        return ans%1000000007;
    }
};