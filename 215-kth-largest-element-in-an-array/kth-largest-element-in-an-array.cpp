class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>max_heap;
        for(auto it:nums){
            max_heap.push(it);
        }  
        for(int i=0;i<k-1;i++){
            max_heap.pop();
        }
        return max_heap.top();
    }
};