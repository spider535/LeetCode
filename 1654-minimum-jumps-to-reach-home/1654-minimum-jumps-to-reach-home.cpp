class Solution {
public:
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int vis[100000] = {false};
        // int vis1[100000] = {false};
        for(auto &it : forbidden){
            vis[it] = true;
            // vis1[it] = true;
        }
        int ans = 0;
        if(x == 0)
            return 0;
        queue<pair<int,int>> qe;
        qe.push({0,0});
        vis[0] = true;
        while(!qe.empty()){
            int n = qe.size();
            while(n--){
                int c = qe.front().first;
                int t = qe.front().second;
                qe.pop();
                if(c+a == x || (!t && c-b == x))
                    return ans+1;
                if(!t && c-b >= 0 && !vis[c-b]){
                    vis[c-b] = true;
                    qe.push({c-b,1});
                }
                if(c+a < 100000 && !vis[c+a]){
                    // vis1[c+a] = true;
                    vis[c+a] = true;
                    qe.push({c+a,0});
                }
            }
            ans++;
        }
        return -1;
    }
};