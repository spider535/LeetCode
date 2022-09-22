class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long int> temp(n,0);
        for(int i = 0; i < n; i++){
            temp[edges[i]] += 1ll*i;
        }
        int ans = -1;
        long long int mx = 0;
        for(int i = 0; i < n ; i++){
            if(temp[i] > mx){
                mx = temp[i];
                ans = i;
            }
        }
        return ans;
    }
};