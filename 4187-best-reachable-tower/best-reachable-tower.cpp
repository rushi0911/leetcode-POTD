class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        vector<int>temp_idx(2,-1);
        int maxi = -1;
        for(auto it:towers){
            int temp_radius = abs(center[0] - it[0]) + abs(center[1] - it[1]);
            cout<<temp_radius<<endl;
            if(temp_radius <= radius){
                if(maxi < it[2]){
                    temp_idx = {it[0],it[1]};
                    maxi = it[2];
                }else if(maxi == it[2]){
                    if(temp_idx[0] >= it[0] || (temp_idx[0] == it[0] && temp_idx[1] > it[1])){
                        temp_idx = {it[0],it[1]};
                    }
                    maxi = it[2];
                }
            }
        }
        return temp_idx;
    }
};