class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i]+=1;
        }
        for(int i=0;i<n;i++){
            int idx = abs(nums[i]);
            if(nums[idx]<0){
                ans.push_back(abs(nums[i])-1);
            }else{
                nums[idx] *= -1;
            }
        }
        return ans;
    }
};