class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        int cnt=0;
        for(auto it:mp){
            if(it.second>1){
                int x = it.second-1;
                int sum = x*(x+1)/2;
                cnt+=sum;
            }
        }
        return cnt;
    }
};