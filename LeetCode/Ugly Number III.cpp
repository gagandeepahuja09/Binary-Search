class Solution {
public:
    long gcd(long a, long b) {
        if(a == 0)
            return b;
        return gcd(b % a, a);
    }
    
    long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }
    
    long countFactors(long num, long a, long b, long c) {
        return num / a + num / b + num / c - num / lcm(a, b) - num / lcm(b, c) - num / lcm(a, c) + num / lcm(a, lcm(b, c));
    }
    
    int nthUglyNumber(int n, int a, int b, int c) {
        long l = 1, h = 2 * 1e9, ans = 2 * 1e9;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(countFactors(m, (long)a, (long)b, (long)c) >= (long)n) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        // cout << countFactors(4, a, b, c) << endl;
        // cout << countFactors(3, a, b, c) << endl;
        return (int)ans;
    }
};
