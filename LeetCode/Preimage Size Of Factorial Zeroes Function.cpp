class Solution {
public:
    long trailingZeroes(long num, int ans = 0) {
        for(long i = 5; num / i ; i *= 5) {
            ans += (num / i);
        }
        return ans;
    }
    
    // no. of nums with trailing zeroes <= K
    long binarySearch(int K) {
        long low = 0, high = 5LL * (K + 1), ans = 0;
        while(low <= high) {
            long mid = (low) + (high - low) / 2;
            if(trailingZeroes(mid) <= K) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return high;
    }
    
    int preimageSizeFZF(int K) {
        if(K == 0)
            return 5;
        return (int)(binarySearch(K) - binarySearch(K - 1));
    }
};
