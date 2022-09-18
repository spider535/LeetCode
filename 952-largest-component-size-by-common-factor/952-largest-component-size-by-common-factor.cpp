class Solution {
public:
    int _find(int i,vector<int>& parent)
    {
        if(parent[i] == -1)
            return parent[i] = i;
        if(parent[i] == i)
            return i;
        else
            return parent[i] = _find(parent[i],parent);
    }
    void _union(int i , int j, vector<int> &parent)
    {
        int xx = _find(i,parent);
        int yy = _find(j,parent);
        if(xx != yy)
        {
            parent[xx] = yy;
        }
    }
    int largestComponentSize(vector<int>& nums) {
        vector<int> parent(100000+1,-1);
        
        for(auto &n: nums)
        {
            for(int i = 2; i*i <= n; i++)
            {
                if(n%i == 0)
                {
                    //is factor
                    _union(i,n,parent);
                    _union(i,n/i,parent);
                }
            }
        }
        unordered_map<int,int> mp;
        int ans = 0;
        for(auto &it : nums){
            int x = _find(it,parent);
            mp[x]++;
            ans = max(ans,mp[x]);
        }
        return ans;
    }
};