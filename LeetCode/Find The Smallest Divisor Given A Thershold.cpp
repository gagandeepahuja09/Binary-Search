class Solution {
public:
    int divSum(vector<int>& A, int m) {
        int ans = 0;
        for(int i = 0; i < A.size(); i++) {
            ans += ((A[i] / m) + ((A[i] % m) != 0));
        }
        return ans;
    }
    
    int smallestDivisor(vector<int>& nums, int thr) {
        int l = 1, h = 1e6 + 1;
        int ans = h;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(divSum(nums, m) <= thr) {
                ans = m;
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return ans;
    }
};
