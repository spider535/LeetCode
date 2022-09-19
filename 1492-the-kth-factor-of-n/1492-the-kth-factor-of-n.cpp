class Solution {
public:
    int kthFactor(int n, int k) {
        int t = 0;
        vector<int>v1;
        vector<int>v2;
        for(int i =1 ; i*i <= n ; i++){
            if(n%i == 0){
                v1.push_back(i);
                if(i*i != n)
                    v2.push_back(n/i);
            }
        }
        if(v1.size() >= k)
            return v1[k-1];
        if(v1.size() + v2.size() < k)
            return -1; 
        reverse(v2.begin(),v2.end());
        return v2[k-v1.size()-1];
    }
};