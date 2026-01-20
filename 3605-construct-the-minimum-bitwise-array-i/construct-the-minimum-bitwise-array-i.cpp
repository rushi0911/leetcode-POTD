class Solution {
public:
    int findA(int target) {
        if (target % 2 == 0) return -1;

        for (int i = 0; i < 30; ++i) {
            if ((target & (1 << i)) && !(target & (1 << (i + 1)))) {
                return target ^ (1 << i);
            }
        }
        return -1;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (int n : nums) {
            ans.push_back(findA(n));
        }
        return ans;
    }
};
