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
        long low = 0, high = 5LL * (K + 1);
        while(low <= high) {
            long mid = (low) + (high - low) / 2;
            long count = trailingZeroes(mid);
            if(count < K)
                low = mid + 1;
            else if(count > K)
                high = mid - 1;
            else
                return 5;
        }
        return 0;
    }
    
    int preimageSizeFZF(int K) {
        return (int)(binarySearch(K));
    }
};
