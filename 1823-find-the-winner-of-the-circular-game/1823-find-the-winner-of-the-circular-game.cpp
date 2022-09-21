class Solution {
public:
    void helper(vector<int>& temp,int st,int k){
        if(temp.size() == 1)
            return;
        int n = temp.size();
        st += k;
        st %= n;
        temp.erase(temp.begin()+st);
        helper(temp,st,k);
    }
    int findTheWinner(int n, int k) {
        vector<int> temp(n);
        k--;
        for(int i = 0 ; i < n ; i++){
            temp[i] = i+1;
        }
        helper(temp,0,k);
        return temp[0];
    }
};