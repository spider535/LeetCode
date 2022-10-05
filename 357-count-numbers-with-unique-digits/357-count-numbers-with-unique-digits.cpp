class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        n--;
        int x = 9;
        int z = 10;
        int y = 9;
        while(n--){
            x *= y;
            z += x;
            y--;
        }
        return z;
    }
};