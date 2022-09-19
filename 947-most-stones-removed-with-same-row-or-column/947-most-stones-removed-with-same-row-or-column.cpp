class Solution {
public:
    unordered_map<int,int> par;
    int island = 0;
    int _find(int x){
        if(!par.count(x)){
            island++;
            return par[x] = x;
        }
        if(x != par[x])
            return par[x] = _find(par[x]);
        return x;
    }
    void _union(int x,int y){
        int xx = _find(x);
        int yy = _find(y);
        if(xx != yy){
            par[xx] = yy;
            island--;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        for(int i = 0 ; i < n ; i++){
            _union(stones[i][0],~stones[i][1]);
        }
        return n-island;
    }
};