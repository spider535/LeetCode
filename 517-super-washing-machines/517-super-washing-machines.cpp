class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int x = 0;
        for(auto &it : machines)
            x += it;
        int n = machines.size();
        if(x%n != 0)
            return -1;
        x = x/n;
        int ans = 0 , avl = 0;
        for(auto &it : machines){
            avl += it-x;
            ans = max(ans,max(abs(avl),it-x));
        }
        return ans;
    }
};