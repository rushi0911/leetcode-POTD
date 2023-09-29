class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return true;
        }
        bool flag1 = false;
        bool flag2 = false;
        for(int i=1;i<n;i++){
            int x = nums[i]-nums[i-1];
            if(x<0){
                flag1 = true;
            }else if(x>0){
                flag2 = true;
            }
        }
        if(!flag1 && flag2){
            return true;
        }
        if(flag1 && !flag2){
            return true;
        }
        if(!flag1 && !flag2){
            return true;
        }
        return false;
    }
};