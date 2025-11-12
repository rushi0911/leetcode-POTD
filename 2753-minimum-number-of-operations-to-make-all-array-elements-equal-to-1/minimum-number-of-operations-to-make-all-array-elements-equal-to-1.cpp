class Solution {
public:
    int gcd(int num1, int num2)
{
    if (num1 == 0)
       return num2;
    if (num2 == 0)
       return num1;
    if (num1 == num2)
        return num1;
    if (num1 > num2)
        return gcd(num1-num2, num2);
    return gcd(num1, num2-num1);
}
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        int mini = 1e9;
        int n=nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 1)
                cnt++;
        }
        if(cnt!= 0)
            return n-cnt;
        for (int i = 0; i < n; i++)
        {
            int res = nums[i];
            for (int j = i + 1; j < n; j++)
            {
                res = gcd(nums[j],res);
                if (res == 1)
                {
                    mini = min(mini, j-i);
                    break;
                }
            }
        }

        if (mini == 1e9)
            return -1;
        mini = mini - 1;
        return n + mini;
    }
};