class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int idx = -1;
        for(int i=0;i<n;i++){
            if(idx == -1 && nums[i] == 1){
                idx = i;
            }else{
                if(nums[i]){
                    int temp = i-idx-1;
                    if(temp < k) return false;
                    idx = i;
                }
            }
        }
        return true;
    }
};