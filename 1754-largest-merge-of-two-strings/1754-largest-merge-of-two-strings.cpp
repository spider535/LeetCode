class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int m = word1.size() , n = word2.size() , i = 0 , j = 0;
        while(i < m && j < n){
            if(word1.substr(i) > word2.substr(j)){
                ans.push_back(word1[i++]);
            }
            else
                ans.push_back(word2[j++]);
        }
        if(i == m)
            return ans+word2.substr(j);
        return ans+word1.substr(i);
    }
};