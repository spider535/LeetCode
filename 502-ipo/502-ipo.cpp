class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> temp;
        int n = profits.size();
        for(int i = 0 ; i < n ; i++){
            temp.push_back({capital[i],profits[i]});
        }
        sort(temp.begin(),temp.end());
        int i = 0;
        while(i < n && temp[i].first <= w)
            pq.push(temp[i++].second);
        while(k && !pq.empty()){
            w += pq.top();
            pq.pop();
            k--;
            while(i < n && temp[i].first <= w)
                pq.push(temp[i++].second);
        }
        return w;
    }
};