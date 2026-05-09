class Solution {
public:
    int totalFruit(vector<int>& s) {
        int n = s.size();
        unordered_map<int,int>mp;
        int i=0,j=0;
        int maxi = -1e9;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()>2){
                // maxi = max(maxi,j-i);
                while(mp.size()>2){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};