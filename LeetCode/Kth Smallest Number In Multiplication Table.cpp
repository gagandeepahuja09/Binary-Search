#define ll long long int

class Solution {
public:
    int countSmall(int mid, int n, int m) {
        int count = 0;
        for(int i = 1; i <= n; i++) {
            count += min(mid / i, m);
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 1, h = m * n;
        while(l < h) {
            int mid = (l + h) / 2;
            if(countSmall(mid, m, n) < (ll)k)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};
