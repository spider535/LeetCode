class Solution {
public:
    long long helper(vector<int>& n1,vector<int>& n2,long long m){
        long long cnt = 0;
        for (int p1 = 0, p2 = n2.size() - 1; p1 < n1.size(); ++p1) {
            while (p2 >= 0 && 1ll * n1[p1] * n2[p2] > m)
                --p2;
            cnt += p2 + 1;
        }
        return cnt;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        auto x1 = lower_bound(nums1.begin(),nums1.end(),0);
        auto x2 = lower_bound(nums2.begin(),nums2.end(),0);
        vector<int> neg1(nums1.begin(),x1),neg2(nums2.begin(),x2);
        vector<int> pos1(x1,nums1.end()),pos2(x2,nums2.end());
        vector<int> rneg1(neg1.rbegin(),neg1.rend()) , rneg2(neg2.rbegin(),neg2.rend());
        vector<int> rpos1(pos1.rbegin(),pos1.rend()) , rpos2(pos2.rbegin(),pos2.rend());
        long long l = -1e10 , r = 1e10;
        while(l < r){
            long long mid = l+(r-l)/2;
            long long cnt = 0;
            if(mid < 0){
                cnt = helper(rpos1,neg2,mid)+helper(rpos2,neg1,mid);
            }
            else
                cnt = helper(pos1,pos2,mid)+helper(rneg1,rneg2,mid)+(neg1.size()*pos2.size())+(neg2.size()*pos1.size()); 
            if(cnt < k)
                l = mid+1;
            else
                r = mid;
        }
        return l;
    }
};