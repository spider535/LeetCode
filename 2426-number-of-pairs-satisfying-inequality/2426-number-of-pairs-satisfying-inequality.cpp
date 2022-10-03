class Solution {
public:
    vector<int> bit;
    void update(int i,int val){
        while(i < 1e5){
            bit[i] += val;
            i += (i&-i);
        }
    }
    int query(int i){
        long long ans = 0;
        while(i > 0){
            ans += 1ll*bit[i];
            i -= (i&-i);
        }
        return ans;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int d) {
        int n = nums2.size();
        vector<int> temp(n);
        for(int i = 0 ; i < n ; i++){
            temp[i] = nums1[i]-nums2[i];
            temp[i] += 20000;
        }
        bit.resize(1e5,0);
        long long ans = 0;
        for(int i = n-1 ; i >= 0 ; i--){
            ans += 1ll*(query(1e5-2) - query(temp[i]-d));
            update(temp[i]+1,1);
            
        }
        return ans;
    }
};