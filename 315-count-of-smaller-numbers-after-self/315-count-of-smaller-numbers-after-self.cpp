class Solution {
public:
    vector<int> seg;
    void update(long long i,int ind,int val,int tl,int tr){
        if(tr < tl)
            return;
        if(tl == tr){
            seg[i] += val;
            return;
        }
        int mid = tl+(tr-tl)/2;
        if(mid >= ind)
            update(1ll*2*i+1,ind,val,tl,mid);
        else
            update(1ll*2*i+2,ind,val,mid+1,tr);
        
        seg[i] = seg[1ll*2*i+1]+seg[1ll*2*i+2];
    }
    int range(long long i,int l,int r,int tl,int tr){
        if(tl > r || tr < l)
            return 0;
        if(tl == l && tr == r)
            return seg[i];
        int mid = tl+(tr-tl)/2;
        int t1 = range(1ll*2*i+1,l,min(r,mid),tl,mid);
        int t2 = range(1ll*2*i+2,max(mid+1,l),r,mid+1,tr);
        return t1+t2;
    }
    vector<int> countSmaller(vector<int>& nums) {
        seg.resize(80000,0);
        vector<int> ans;
        int n = nums.size();
        for(int i = n-1 ; i >= 0 ; i--){
            ans.push_back(range(0,-10000,nums[i]-1,-10000,10000));
            update(0,nums[i],1,-10000,10000);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};