class Solution {
public:
    
    int nthMagicalNumber(int n, int a, int b) {
        const long MOD = 1e9 + 7;
        long low = min((long)a, (long)b), high = min((long)a, (long)b) * 1e9, ans = low;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            long countFactors = mid / a + mid / b - mid / lcm(a, b);
            if(countFactors < (long)n) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                ans = mid;
            }
        }
        return (int)(ans % MOD);
    }
};
