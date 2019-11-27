class Solution {
public:
    bool isPossible(vector<int>& nums, long m, int k) {
        long sum = 0;
        int cnt = 1;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > m) {
                sum = nums[i];
                cnt++;
            }
        }
        return (cnt <= k);
    }
    
    int splitArray(vector<int>& nums, int k) {
        long h = 0, l = 0;
        for(int i : nums)
            h += i, l = max(l, (long)i);
        while(l <= h) {
            long m = l + (h - l) / 2;
            if(isPossible(nums, m, k)) {
                h = m - 1;
            }
            else
                l = m + 1;
        }
        return (int)l;
    }
};
