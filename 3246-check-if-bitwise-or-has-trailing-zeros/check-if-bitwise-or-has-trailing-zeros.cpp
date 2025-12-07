class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(auto it:nums){
            if(it % 2 == 0) cnt++;
            if(cnt >= 2) break;
        }
        return cnt == 2 ? true : false;
    }
};