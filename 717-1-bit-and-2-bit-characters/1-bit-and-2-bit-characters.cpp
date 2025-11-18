class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        stack<int>st;
        int i = 0;
        int n = bits.size();
        bool flag = false;
        while(i<n){
            if(st.empty() && bits[i] == 1){
                st.push(bits[i]);
                flag = false;
            }else{
                if(!st.empty() && st.top() == 1){
                    st.pop();
                }else{
                    flag = true;
                }
            }
            i++;
        }
        if(flag) return true;
        return false;
    }
};