class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> eff(n,vector<int>(m,1e9));
        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int wt = x.first;
            int u = x.second.first;
            int v = x.second.second;
            if(wt >= eff[u][v])
                continue;
            eff[u][v] = wt;
            for(auto &it : dir){
                int x1 = u+it.first;
                int y1 = v+it.second;
                if(x1 < 0 || y1 < 0 || x1 == n || y1 == m)
                    continue;
                int temp = max(wt,abs(heights[x1][y1]-heights[u][v]));
                if(temp >= eff[x1][y1])
                    continue;
                pq.push({temp,{x1,y1}});
            }
        }
        return eff[n-1][m-1];
    }
};