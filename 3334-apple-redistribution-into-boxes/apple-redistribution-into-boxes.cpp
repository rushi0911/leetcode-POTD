class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        int sum = 0;
        for(auto it : apple){
            sum+=it;
        }
        int temp = 0;
        int cnt = 0;
        sort(capacity.begin(),capacity.end());
        reverse(capacity.begin(),capacity.end());
        for(auto it : capacity){
            temp += it;
            cnt++;
            if(temp >= sum){
                return cnt;
            }
        }
        return cnt;
    }
};