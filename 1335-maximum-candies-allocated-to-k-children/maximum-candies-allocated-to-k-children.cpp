#include <numeric>
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        long long total = 0;
        for(auto it: candies){
            total+=it;
        }
        if(total < k){
            return 0;
        }
        long long low = 1, high = total;
        while(low <= high){
            long long mid = low + (high-low)/2;
            long long temp_sum = 0;
            for(auto it: candies){
                temp_sum += (it/mid);
            }
            if(temp_sum < k){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return high%1000000007;
    }
};