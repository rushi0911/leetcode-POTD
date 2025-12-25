class Solution {
public:
    long long maximumHappinessSum(vector<int>& nums, int k) {
        int n = nums.size();
        int dlt = 0;
        long long ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=0;i--){
            if(nums[i] > dlt) ans += 1LL*(nums[i]-dlt);
            k--;
            dlt++;
            if(k <= 0) break;
        }
        return ans;
    }
};