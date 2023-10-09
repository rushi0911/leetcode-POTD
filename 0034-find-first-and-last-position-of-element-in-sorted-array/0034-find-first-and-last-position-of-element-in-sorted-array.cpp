class Solution {
public:
int firstOccurance(vector<int>& nums, int target){
int n = nums.size();
int low = 0,high = n-1;
while(low<=high){
    int mid = low+(high-low)/2;
    if((mid==0 && nums[mid]==target) || (nums[mid]==target && nums[mid-1]!=target)){
        // ans.push_back(nums[mid]);
        return mid;
    }
    else if(nums[mid]<target){
        low = mid+1;
        }
    else if(nums[mid]>=target){
            high = mid-1;
            }
        }
        return -1;
}
int lastOccurance(vector<int>& nums, int target){
int n = nums.size();
int low = 0,high = n-1;
while(low<=high){
    int mid = low+(high-low)/2;
    if((mid==(n-1) && nums[mid]==target)  || (nums[mid]==target && nums[mid+1]!=target)){
        return mid;
    }
    else if(nums[mid]<=target){
        low = mid+1;
        }
    else if(nums[mid]>target){
            high = mid-1;
            }
        }
        return -1;
}
    vector<int> searchRange(vector<int>& nums, int target) {
           int n = nums.size();
           int f = firstOccurance(nums,target);
           int l = lastOccurance(nums,target);
           vector<int>ans;
           ans.push_back(f);
           ans.push_back(l);
           return ans;
    }
};