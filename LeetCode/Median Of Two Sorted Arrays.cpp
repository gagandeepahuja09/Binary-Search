class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0, r = m, mid1, mid2, maxl, minr;
        while (l <= r) {
            mid1 = (l+r)/2;
            mid2 = ((m + n + 1) >> 1) - mid1;
            if (mid1 > 0 && nums1[mid1-1] > nums2[mid2]) {
                r = mid1 - 1;
            } else if (mid1 < m && nums1[mid1] < nums2[mid2 - 1]) {
                l = mid1 + 1;
            } else {
                if (mid1 == 0) {
                    maxl = nums2[mid2 - 1];
                } else if (mid2 == 0) {
                    maxl = nums1[mid1 - 1];
                } else {
                    maxl = max(nums1[mid1 - 1], nums2[mid2 - 1]);
                }
                if ((m + n) % 2 == 1) {
                    return maxl;
                }
                if (mid1 == m) {
                    minr = nums2[mid2];
                } else if (mid2 == n) {
                    minr = nums1[mid1];
                } else {
                    minr = min(nums1[mid1], nums2[mid2]);
                }
                return (maxl + minr) / 2.0;
            }
        }
    }
};
