class Solution {
public:
    vector<int> ans;
    void helper(int i,int n){
        if(i > n)
            return;
        ans.push_back(i);
        for(int j = 0 ; j < 10 ; j++){
            helper(i*10+j,n);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int j = 1 ; j < 10 ; j++){
            helper(j,n);
        }
        return ans;
    }
};