class Solution {
public:
    static bool mycomp(vector<int> &a, vector<int>&b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),mycomp);
        int cnt=0;
        vector<int>temp = intervals[0];
        for(auto it:intervals){
            if(temp[1] > it[0]){
                cnt++;
            }else{
                temp = it;
            }
        }
        return cnt-1;
    }
};