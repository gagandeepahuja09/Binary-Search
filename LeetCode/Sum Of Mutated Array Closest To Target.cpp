class Solution {
public:
    int findBestValue(vector<int>& A, int target) {
        sort(A.begin(), A.end());
        vector<int> sum;
        int n = A.size();
        sum.push_back(A[0]);
        for(int i = 1; i < A.size(); i++) {
            sum.push_back(sum.back() + A[i]);
        }
        int ans = 0, diff = target;
        for(int i = 1; i <= target; i++) {
            auto pos = upper_bound(A.begin(), A.end(), i);
            int p, tot;
            if(pos != A.begin()) {
                pos--;
                p = pos - A.begin();
                tot = sum[p] + i * (n - 1 - p);
            }
            else {
                tot = i * n;
            }
            if(abs(tot - target) < diff) {
                ans = i;
                diff = abs(tot - target);
            }
        }
        return ans;
    }
};
