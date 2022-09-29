class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> m;
        for(auto it : s){
            m[it]++;
        }
        priority_queue<pair<int,char> > pq;
        for(auto it : m){
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty()){
            char temp= pq.top().second;
            int temp2 = pq.top().first;
            pq.pop();
            temp2--;
            ans.push_back(temp);
            if(!pq.empty()){
                char temp3= pq.top().second;
                int temp4 = pq.top().first;
                pq.pop();
                temp4--;
                if(temp4 > 0)
                    pq.push({temp4,temp3});
                ans.push_back(temp3);
            }
            else if(temp2 > 0)
                return "";
            if(temp2 > 0)
                pq.push({temp2,temp});
            
        }
        return ans;
    }
};