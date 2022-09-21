class Solution {
public:
    string convert(string s, int n) {
        if(n == 1)
            return s;
        int m = s.length();
        vector<vector<char>> temp(n,vector<char>(m,'$'));
        int i = 0 , j = 0;
        bool f = true;
        for(auto &it : s){
            // cout<<i<<" "<<j<<endl;
            temp[i][j] = it;
            if(f){
                i++;
            }
            if(f && i == n-1){
                f = false;
            }
            else if(!f){
                i--;
                j++;
            }
            if(i == 0){
                f = true;
            }
        }
        string ans;
        for(auto &it : temp){
            for(auto &ir : it){
                if(ir != '$')
                    ans.push_back(ir);
            }
        }
        return ans;
    }
};