class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int x = target - numbers[i];
            if(mp.count(x)){
                ans.push_back(mp[x]+1);
                ans.push_back(i+1);
            }else{
                mp[numbers[i]] = i;
            }
        }
        return ans;
    }
};