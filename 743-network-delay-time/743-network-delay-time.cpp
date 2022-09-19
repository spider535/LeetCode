class Solution {
public:
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n];
        for(auto &it : times){
            adj[it[0]-1].push_back({it[1]-1,it[2]});
        }
        vector<int> dis(n,1e9);
        //dijastra
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k-1});
        while(!pq.empty()){
            int wt = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if(dis[v] <= wt)
                continue;
            dis[v] = wt;
            for(auto &u : adj[v]){
                if(dis[u.first] > wt+u.second)
                    pq.push({wt+u.second,u.first});
            }
        }
        int ans = *max_element(dis.begin(),dis.end());
        return ans == 1e9 ? -1 : ans;
    }
};