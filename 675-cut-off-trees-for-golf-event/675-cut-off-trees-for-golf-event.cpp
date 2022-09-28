class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(forest[i][j] > 1){
                    pq.push({forest[i][j],{i,j}});
                }
            }
        }
        int ci = 0 , cj = 0;
        int ans = 0;
        while(!pq.empty()){
            auto zz = pq.top();
            pq.pop();
            int ti = zz.second.first;
            int tj = zz.second.second;
            vector<vector<bool>> vis(m,vector<bool>(n,false));
            queue<pair<int,int>> qe;
            qe.push({ci,cj});
            vis[ci][cj] = true;
            int temp = 0;
            bool flag = true;
            while(!qe.empty() && flag){
                int n1 = qe.size();
                temp++;
                while(n1-- && flag){
                    auto z = qe.front();
                    qe.pop();
                    ci = z.first;
                    cj = z.second;
                    if(ci == ti && cj == tj){
                        temp--;
                        flag = false;
                        break;
                    }
                    for(auto &it : dir){
                        int x = ci+it.first;
                        int y = cj+it.second;
                        if(x < 0 || y < 0 || x == m || y == n || forest[x][y] == 0 || vis[x][y])
                            continue;
                        if(x == ti && y == tj){
                            ci = x;
                            cj = y;
                            flag = false;
                            break;
                        }
                        vis[x][y] = true;
                        qe.push({x,y});
                    }
                }
            }
            if(!flag){
                ans += temp;
            }
            else
                return -1;
        }
        return ans;
    }
};