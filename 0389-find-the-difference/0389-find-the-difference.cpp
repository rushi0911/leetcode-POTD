class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int>vec_char(26,0);
        for(auto it:t){
            vec_char[it-'a']++;
        }
        for(auto it:s){
            if(vec_char[it-'a']){
                vec_char[it-'a']--;
            }
        }
        for(int i=0;i<26;i++){
            if(vec_char[i]==1){
                return 'a'+i;
            }
        }
        return '-1';
    }
};