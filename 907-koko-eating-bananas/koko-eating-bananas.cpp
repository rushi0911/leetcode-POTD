class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = *max_element(piles.begin(),piles.end());
        while(low <= high){
            int mid = low + (high-low)/2;
            long long total = 0;
            for(int i=0;i<n;i++){
                total += ceil((double)piles[i]/(double)mid);
            }
            if(total <= h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};