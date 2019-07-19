class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, h = A.size() - 1, m;
        while(l <= h) {
            m = l + (h - l) / 2;
            if((m == 0 || A[m] > A[m - 1]) && (m == A.size() - 1 || A[m] > A[m + 1])) {
                return m;
            }
            else if(m == 0 || A[m] < A[m - 1]) {
                h = m - 1;
            }
            else {
                l = m + 1;
            }
        }
        return m;
    }
};
