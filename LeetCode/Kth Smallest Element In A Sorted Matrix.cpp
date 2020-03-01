class Solution {
public:
    int countSmaller(vector<vector<int>>& matrix, int i, long val) {
        int low = 0, high = matrix.size() - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if((long)matrix[i][mid] < val) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    int countLess(vector<vector<int>>& matrix, long val) {
        int count = 0;
        for(int i = 0; i < matrix.size(); i++) {
            int cs = countSmaller(matrix, i, val) + 1;
            count += cs;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        long low = INT_MIN, high = INT_MAX, ans = INT_MIN;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            int c = countLess(matrix, mid);
            if(c <= k - 1) {
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
