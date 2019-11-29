class Solution {
public:
    int arrangeCoins(int n) {
        long l = 0, h = n;
        while(l <= h) {
            long m = l + (h - l) / 2;
            if((long)(m * (m + 1) / 2) <= (long)n) {
                l = m + 1;
            }
            else
                h = m - 1;
        }
        return (int)h;
    }
};
