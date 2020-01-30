class Solution {
public:
    int eatingHours(vector<int>& piles, int val) {
        int ans = 0;
        for(int i = 0; i < piles.size(); i++) {
            ans += ((piles[i] / val) + ((piles[i] % val) != 0 ? 1 : 0));
        }
        return ans;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(eatingHours(piles, mid) <= H) {
                high = mid - 1;
                ans = mid;
            }
            else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};
