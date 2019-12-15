class Solution {
public:
    int sum(vector<vector<int>>& dp, int i, int j, int x, int y) {
        return dp[x][y] - dp[x][j] - dp[i][y] + dp[i][j]; 
    }
    
    int maxSideLength(vector<vector<int>>& mat, int th) {
        int ans = 1000;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + mat[i][j]; 
            }
        }
        int l = 1, h = min(m, n);
        while(l < h) {
            int mid = (h + l + 1) / 2;
            bool f = false;
            for(int i = 0; i <= n; i++) {
                for(int j = 0; j <= m; j++) {
                    if(i + mid <= n && j + mid <= m) {
                        int s = sum(dp, i, j, i + mid, j + mid);
                        if(s <= th) {
                            f = true;
                            break;
                        }
                    }
                }
            }
            if(f) {
                l = mid;
                ans = mid;
            }
            else {
                h = mid - 1;
            }
        }
        if(ans == 1000)
            return 0;
        return l;
    }
};
