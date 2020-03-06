class Solution {
public:
    bool heatPossible(vector<int>& houses, vector<int>& heaters, int radius) {
        int j = 0;
        for(int i = 0; i < heaters.size(); i++) {
            while(j < houses.size() && abs(heaters[i] - houses[j]) <= radius)
                j++;
        }
        return j >= houses.size();
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int low = 0, high = max(houses.back(), heaters.back()), ans = high;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(heatPossible(houses, heaters, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
