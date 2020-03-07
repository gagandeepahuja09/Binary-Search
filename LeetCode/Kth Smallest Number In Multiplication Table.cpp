class Solution {
public:
    int countSmaller(int m, int n, int val) {
        int count = 0;
        for(int i = 1; i <= m; i++) {
            int cs = val / i;
            if(val % i == 0)
                cs--;
            count += min(n, cs);
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int low = 1, high = m * n, ans = 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(countSmaller(m, n, mid) < k) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
