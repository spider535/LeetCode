class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = accumulate(chalk.begin(),chalk.end(),0ll);
        k = k%sum;
        int n = chalk.size();
        for(int i = 0 ; i < n ; i++){
            if(chalk[i] > k)
                return i;
            k -= chalk[i];
        }
        return -1;
    }
};