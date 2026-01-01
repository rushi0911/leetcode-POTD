class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int>ans;
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            if(carry == 0) break;
        }
        if(carry){
            digits.resize(n+1);
            digits[0] = carry;
            for(int i=n;i>1;i--){
                digits[i] = digits[i-1];
            }
        }
        return digits;
    }
};