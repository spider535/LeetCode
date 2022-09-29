class Solution {
public:
    vector<string> ans;
    void helper(unordered_map<string,multiset<string>> &adj,string ss){
        while(!adj[ss].empty()){
            string temp = *(adj[ss].begin());
            adj[ss].erase(adj[ss].begin());
            helper(adj,temp);
        }
        ans.push_back(ss);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string,multiset<string>> adj;
        for(auto &it : tickets){
            adj[it[0]].insert(it[1]);
        }
        helper(adj,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};