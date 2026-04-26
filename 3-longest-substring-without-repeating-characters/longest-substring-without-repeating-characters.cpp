class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int i=0,j=0;
        int maxi = 0;
        while(j<n){
            if(mp[s[j]]){
                while(!mp.empty() && mp[s[j]]){
                    mp[s[i]]--;
                    i++;
                    if(mp[s[j]]==0){
                        mp.erase(s[j]);
                    }
                }
            }else{
                maxi = max(j-i+1,maxi);
            }
            mp[s[j]]++;
            j++;
        }   
        return maxi;
    }
};