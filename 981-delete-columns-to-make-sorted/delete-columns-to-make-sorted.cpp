class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r = strs.size();
        int c = strs[0].size();
        int cnt=0;
        for(int i=0;i<c;i++){
            for(int j=0;j<r-1;j++){
                if(((int)strs[j][i])>((int)strs[j+1][i]))
                {
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};