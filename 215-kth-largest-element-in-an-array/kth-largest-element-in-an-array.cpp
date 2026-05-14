class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int>max_heap;
        for(auto it:nums){
            max_heap.push(it);
        }
        k--;
        while(k--){
            max_heap.pop();
        }
        return max_heap.top();
    }
};