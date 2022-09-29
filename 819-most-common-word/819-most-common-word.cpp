class Solution {
public:
    string mostCommonWord(string par, vector<string>& banned) {
        set<string> ban;
        ban.insert("");
        for(auto &it : banned){
            for(auto &ir : it)
                ir = tolower(ir);
            ban.insert(it);
        }
        int n = par.size();
        unordered_map<string,int> mp;
        int i = 0;
        while(i < n){
            while(i < n && !isalpha(par[i]))
                i++;
            string temp = "";
            while(i < n && isalpha(par[i])){
                temp.push_back(tolower(par[i++]));
            }
            if(!ban.count(temp))
                mp[temp]++;
        }
        int mx = 0;
        string ans;
        for(auto &it : mp){
            if(it.second > mx){
                mx = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};