class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> pr;
        pr.push_back(1);
        while(r--){
            vector<int> temp;
            temp.push_back(1);
            for(int i = 1 ; i < pr.size() ; i++){
                temp.push_back(pr[i-1]+pr[i]);
            }
            temp.push_back(1);
            pr = temp;
        }
        return pr;
    }
};