class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int l = 0 , r = arr.size()-1;
        int ans = 0;
        for(auto &it : arr){
            int a = l/2 +1, b = r/2 +1;
            int c = (l+1)/2 , d = (r+1)/2;
            ans += a*b*it + c*d*it;
            l++;
            r--;
        }
        return ans;
    }
};