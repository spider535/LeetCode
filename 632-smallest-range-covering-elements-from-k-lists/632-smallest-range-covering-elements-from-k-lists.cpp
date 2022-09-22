class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        int k = nums.size();
        int st,ed;
        int mx = -1e9;
        for(int i = 0 ; i < k ; i++){
            pq.push({nums[i][0],{i,0}});
            mx = max(mx,nums[i][0]);
        }
        st = pq.top().first;
        ed = mx;
        while(!pq.empty()){
            int mn = pq.top().first;
            if(mx-mn < ed-st){
                st = mn;
                ed = mx;
            }
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            y++;
            if(y == nums[x].size())
                return {st,ed};
            mx = max(mx,nums[x][y]);
            pq.push({nums[x][y],{x,y}});
        }
        return {st,ed};
    }
};