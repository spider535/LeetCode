class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        vector<int> left(n),right(n);
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            left[i] = i;
            while(!st.empty() && arr[st.top()] >= arr[i]){
                left[i] = left[st.top()];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i = n-1 ; i >= 0 ; i--){
            right[i] = i;
            while(!st.empty() && arr[st.top()] >= arr[i]){
                right[i] = right[st.top()];
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,(right[i]-left[i]+1)*arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        int ans = 0;
        vector<int> temp(n,0);
        for(auto &it : matrix){
            for(int i = 0 ; i < n ; i++){
                if(it[i] == '0')
                    temp[i] = 0;
                else
                    temp[i]++;
            }
            ans = max(ans,largestRectangleArea(temp));
        }
        return ans;
    }
};