class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        unordered_map<long long,int> cnt;
        for (int i = 0; i < k-1; i++)
            cnt[nums[i]]++;
        set<pair<int,long long>> top, bot;
        long long sum = 0;
        for (auto [num, c] : cnt){
            sum += num * c;
            top.insert({c,num});
        }
        while (top.size() > x){
            auto it = top.begin();
            sum -= it->first * it->second;
            bot.insert(*it);
            top.erase(it);
        }
        vector<long long> res;
        for (int i = k-1; i < nums.size(); i++){
            pair<int,long long> p = {cnt[nums[i]]++,nums[i]};
            if (auto it = top.find(p); it != top.end()){
                top.erase(it); sum += p.second;
                top.insert({p.first+1,p.second});
            }
            else if (top.size() < x){
                sum += (p.first+1) * p.second;
                top.insert({p.first+1,p.second});
            }
            else if (top.lower_bound({p.first+1,p.second}) != top.begin()){
                if (p.first)
                    bot.erase(bot.find(p));
                sum += (p.first+1) * p.second;
                top.insert({p.first+1,p.second});
                it = top.begin();
                sum -= it->first * it->second;
                bot.insert(*it); top.erase(it);
            }
            else if (p.first == 0)
                bot.insert({1,p.second});
            else {
                bot.erase(bot.find(p));
                bot.insert({p.first+1,p.second});
            }
            res.push_back(sum);
            p = {cnt[nums[i-k+1]]--,nums[i-k+1]};
            if (auto it = top.find(p); it != top.end()){
                top.erase(it); sum -= p.second;
                if (p.first == 1){
                    if (bot.size()){
                        it = prev(bot.end(),1);
                        sum += it->first * it->second;
                        top.insert(*it);
                        bot.erase(it);
                    }
                }
                else if (bot.size() && *prev(bot.end(),1) > pair{p.first-1,p.second}){
                    sum -= (p.first-1) * p.second;
                    it = prev(bot.end(),1);
                    sum += it->first * it->second;
                    top.insert(*it);
                    bot.erase(it);
                    bot.insert({p.first-1,p.second});
                }
                else top.insert({p.first-1,p.second});
            }
            else {
                bot.erase(bot.find(p));
                if (p.first > 1)
                    bot.insert({p.first-1,p.second});
            }
        }
        return res;
    }
};