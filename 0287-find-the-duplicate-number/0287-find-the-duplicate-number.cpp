class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int temp = abs(nums[i]);
            if(nums[temp]<0){
                return temp;
            }
            nums[temp] = -nums[temp];
        }
        return -1;
    }
};