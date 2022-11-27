class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if(st.empty())
            return ans;
        int str = -1,ed;
        for(auto &it : st){
            if(str == -1){
                str = it;
                ed = it;
            }
            else if(it == ed+1){
                ed = it;
            }
            else{
                ans.push_back({str,ed});
                str = it;
                ed = it;
            }
        }
        ans.push_back({str,ed});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */