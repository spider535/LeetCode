class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans = {0,1,1,2};
        if(n < 4){
            int x = 4-n-1;
            while(x--)
                ans.pop_back();
            return ans;
        }
        n -= 3;
        while(n > 0){
            int x = ans.size();
            for(int i = 0 ; i < x && n-- ; i++){
                ans.push_back(1+ans[i]);
            }
        }
        return ans;
    }
};