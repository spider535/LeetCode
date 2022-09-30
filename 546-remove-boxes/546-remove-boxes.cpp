class Solution {
public:
    int dp[101][101][101];
    int helper(vector<int>& boxes,int i,int j,int ext){
        if(i > j)
            return 0;
        if(dp[i][j][ext] != -1)
            return dp[i][j][ext];
        if(i == j){
            return (ext+1)*(ext+1);
        }
        int ans = ((ext+1)*(ext+1)) + helper(boxes,i+1,j,0);;
        for(int k = i+1 ; k <= j ; k++){
            if(boxes[i] == boxes[k]){
                ans = max(ans,helper(boxes,i+1,k-1,0)+helper(boxes,k,j,ext+1));
            }
        }
        return dp[i][j][ext] = ans;
    }
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        int n = boxes.size();
        return helper(boxes,0,n-1,0);
    }
};