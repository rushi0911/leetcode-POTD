class Solution {
public:
    long long cur = 0;
    long long arr[101];
    int dl=0;

    string decodeAtIndex(string s, int k) {
        int l = s.size();
        cur = 0;
        dl = 0;
        string c="";

        for(int i = 0; i < l; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                cur++;
            }
            else if(s[i] >= '2' && s[i] <= '9'){
                cur *= s[i]-'0';
            }
            
            arr[i] = cur;

            if(cur >= k){
                dl=i;
                break;
            }
        }

        if(s[dl] >='a' && s[dl] <= 'z') {
            c = s[dl];
        }
        else{
            k %= arr[dl-1];
            if(k==0){
                k = arr[dl-1];
            }
            cout << k << endl;
            return decodeAtIndex(s, k);
        }
        
        return c;
    }
};