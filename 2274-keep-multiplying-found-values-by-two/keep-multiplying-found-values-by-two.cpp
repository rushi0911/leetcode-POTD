class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n = nums.size();
        unordered_set<int>st;
        for(auto it:nums){
            st.insert(it);
        }
        while(st.count(original)){
            original *= 2; 
        }
        return original;
    }
};