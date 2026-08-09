class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        for(auto it: s){
            if(it == '(' || it == '{' || it == '['){
                st.push(it);
            }else{
                if(!st.empty() && ((st.top() == '(' && it == ')') || (st.top() =='{' && it=='}') || (st.top() == '[' && it == ']'))){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        if(st.empty()) return true;
        return false;
    }
};