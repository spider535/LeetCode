class Solution {
public:
    long long int ans = 0;
    void merge(vector<int> &temp,int i,int mid,int j,int d){
        int s1 = i , s2 = mid+1,sz = j-i+1;
        int ind = i;
        vector<int> t(sz);
        for(int k = 0 ; k < sz ; k++){
            if(s2 > j || (s1 <= mid && temp[s1] <= temp[s2]))
                t[k] = temp[s1++];
            else{
                while(ind <= mid && temp[ind] <= 1ll*temp[s2]+d)
                    ind++;
                ans += 1ll*(ind-i);
                t[k] = temp[s2++];
            }
        }
        int k = 0;
        for(; i <= j ; i++){
            temp[i] = t[k++];
        }
    }
    void mergeSort(vector<int> &temp,int i,int j,int d){
        if(i >= j)
            return;
        int mid = i+(j-i)/2;
        mergeSort(temp,i,mid,d);
        mergeSort(temp,mid+1,j,d);
        merge(temp,i,mid,j,d);
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int d) {
        int n = nums2.size();
        vector<int> temp(n);
        for(int i = 0 ; i < n ; i++){
            temp[i] = nums1[i]-nums2[i];
        }
        mergeSort(temp,0,n-1,d);
        return ans;
    }
};