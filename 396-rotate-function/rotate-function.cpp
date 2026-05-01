class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        vector<int> memo (A.size(), 0);
        unsigned long total_A = 0;
        int curr_sum = 0;
        int ans;
        for (auto a:A) total_A+=a;
        for (int i = 0; i < A.size(); ++i){
            curr_sum += ((A.size() - 1 + i) % A.size()) * A[i];
            memo[i] = total_A - A[(A.size() - i) % A.size()] * A.size(); 
        }
        ans = curr_sum;

        for (int i = 0; i < A.size(); ++i){
            curr_sum += memo[i];
            ans = max(ans, curr_sum);
        }
        return ans;
    }
};