class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it:nums){
            int rem = it%3;
            rem = min(rem,3-rem);
            sum+=rem;
        }
        return sum;
    }

};