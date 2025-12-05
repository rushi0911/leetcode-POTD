class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefixSum[i] = sum;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int first_sum = prefixSum[i];
            int second_sum = sum-prefixSum[i];
            if(first_sum && second_sum){
                int temp = abs(first_sum-second_sum);
                if(temp % 2 == 0){
                    cnt ++;
                }
            }
        }
        return cnt;
    }
};