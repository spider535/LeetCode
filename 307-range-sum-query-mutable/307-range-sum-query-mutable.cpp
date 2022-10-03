class NumArray {
public:
    vector<int>a;
    vector<int> bit;
    int sum(int i){
        int ans = 0;
        while(i > 0){
            ans+=bit[i];
            i -= (i&-i);
        }
        return ans;
    }
    void update_(int i,int val){
        while(i < 1e5){
            bit[i] += val;
            i += (i&-i);
        }
        
    }
    NumArray(vector<int>& nums) {
        a = nums;
        int n = nums.size();
        bit.resize(1e5,0);
        for(int i = 0; i < n ;i++){
            update_(i+1,nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = val - a[index];
        a[index] = val;
        update_(index+1,diff);
    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */