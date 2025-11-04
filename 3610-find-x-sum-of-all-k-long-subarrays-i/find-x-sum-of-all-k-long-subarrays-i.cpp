class Solution {
public:
    int solve(unordered_map<int,int>&mp,int x){
        priority_queue<pair<int,int>>maxH;
        for(auto it:mp){
            maxH.push({it.second,it.first});
        }
        int sum = 0;
        while(x-- && !maxH.empty()){
            auto it = maxH.top();
            int loop = it.first;
            while(loop--){
                sum += (it.second);
            }
            maxH.pop();
        }
        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        int i=0,j=0;
        while(j < n){
            mp[nums[j]]++;
            while(i < j && (j-i+1) > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if((j-i+1) == k){
                int temp = solve(mp,x);
                ans.push_back(temp);
            }
            j++;
        }
        return ans;
             
    }
};