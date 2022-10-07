class Solution {
public:
    vector<string> dp;
    string helper(vector<int> &cost,int tar){
        if(tar == 0)
            return "";
        if(dp[tar] != "$")
            return dp[tar];
        string ans = "0";
        for(int i = 0 ; i < 9 ; i++){
            if(cost[i] > tar)
                continue;
            string temp = to_string(i+1)+helper(cost,tar-cost[i]);
            if(temp.back() == '0' || temp.size() < ans.size())
                continue;
            if(temp.size() == ans.size())
                ans = max(ans,temp);
            else
                ans = temp;
        }
        return dp[tar] = ans;
    }
    string largestNumber(vector<int>& cost, int target) {
        dp.resize(target+1,"$");
        return helper(cost,target);
    }
};