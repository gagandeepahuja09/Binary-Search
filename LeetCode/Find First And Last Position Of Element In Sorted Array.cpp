class Solution {
public:
    int findFirstPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            }    
            else {
                low = mid + 1;
            }
        }
        return (ans >= 0 && nums[ans] == target) ? ans : -1;
    }
    
    int findLastPos(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= target) {
                ans = mid;
                low = mid + 1;
            }    
            else {
                high = mid - 1;
            }
        }
        return (ans >= 0 && nums[ans] == target) ? ans : -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size())
            return { -1, -1 };
        int first = findFirstPos(nums, target);
        int last = findLastPos(nums, target);
        return { first, last };
    }
};
