class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int sum = 0;
        unordered_map<char,int>mp;
        for(auto it:customers){
            if(it == 'Y') mp[it]++;
        }
        // mini = mp['Y'];
        int mini_idx = 0;
        if(mp['Y'] == 0){
            return 0;
        }
        int mini = mp['Y'];
        bool flag = false;
        for(int i=0;i<n;i++){
            if(customers[i] == 'Y'){
                if(mp['Y']){
                    mp['Y']--;
                    if(mp['Y'] == 0){
                        mp.erase('Y');
                    }
               }
            }
            if(customers[i] == 'N'){
                mp['N']++;
            }
            sum = sum + mp['Y'] + mp['N'];
            if(sum < mini){
                mini = sum;
                mini_idx = i+1;
            }
            sum = 0;
        }
        return mini_idx;

    }
};