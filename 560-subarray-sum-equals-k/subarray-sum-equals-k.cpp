class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int cnt = 0, sum=0;
        mp[sum] = 1;
        for(auto it:nums){
            sum+=it;
            if(mp[sum-k]) cnt+=(mp[sum-k]);
            mp[sum]++;
        }
        return cnt;
    }
};