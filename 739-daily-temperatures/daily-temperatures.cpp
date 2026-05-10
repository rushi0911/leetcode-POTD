class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int,int>>st;
        vector<int>ans;
        st.push({temperatures[n-1],n-1});
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && (st.top().first <= temperatures[i])){
                st.pop();
            }
            int x = st.empty()?0:(st.top().second - i);
            ans.push_back(x);
            st.push({temperatures[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};