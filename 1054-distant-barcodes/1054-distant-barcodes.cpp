class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> mp;
        for(auto &it : barcodes)
            mp[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto &it : mp){
            pq.push({it.second,it.first});
        }
        int i = 0;
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            barcodes[i++] = x.second;
            x.first--;
            if(x.first > 0){
                auto y = pq.top();
                pq.pop();
                barcodes[i++] = y.second;
                y.first--;
                if(y.first > 0)
                    pq.push(y);
                pq.push(x);
            }
        }
        return barcodes;
    }
};