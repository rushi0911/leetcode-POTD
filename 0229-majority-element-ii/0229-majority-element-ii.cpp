class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0,e1=INT_MIN;
        int cnt2=0,e2=INT_MAX;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=e2){
                cnt1=1;
                e1 = nums[i];
            }
            else if(cnt2==0 && nums[i]!=e1){
                cnt2=1;
                e2 = nums[i];
            }
            else if(nums[i]==e1){
                cnt1++;
            }
            else if(nums[i]==e2){
                cnt2++;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==e1){
                cnt1++;
            }
            else if(nums[i]==e2){
                cnt2++;
            }

        }
        vector<int>ans;
        if(cnt1>(n/3)){
            ans.push_back(e1);
        }
        if(cnt2>(n/3)){
            ans.push_back(e2);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};