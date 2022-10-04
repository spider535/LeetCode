class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int ans = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int i = 0;
        int n = trainers.size();
        for(auto &it : players){
            while(i < n && it > trainers[i])
                i++;
            if(i == n)
                return ans;
            ans++;
            i++;
        }
        return ans;
    }
};