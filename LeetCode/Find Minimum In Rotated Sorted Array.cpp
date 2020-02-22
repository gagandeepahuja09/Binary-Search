class Solution {
 public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1, ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= nums.back()) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return nums[ans];
    }
};
