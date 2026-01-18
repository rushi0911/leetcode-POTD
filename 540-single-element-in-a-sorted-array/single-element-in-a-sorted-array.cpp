class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            cout<<low<<" "<<high<<endl;
            cout<<mid<<endl;
            if(mid == 0 || ((nums[mid] != nums[mid-1]) && (nums[mid] != nums[mid+1]))){
                return nums[mid];
            }
            else if(nums[mid] == nums[mid-1]){
                if((mid-low+1)%2){
                    high = mid-2;
                }else{
                    low = mid+1;
                }
            }
            else if(nums[mid] == nums[mid+1]){
                if((high-mid+1)%2){
                    low = mid+2;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};