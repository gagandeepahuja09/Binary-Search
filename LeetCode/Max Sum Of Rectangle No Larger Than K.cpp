class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& A, int k) {
        int row = A.size(), col = A[0].size(), ret = INT_MIN;
        for(int l = 0; l < col; l++) {
            vector<int> sums(row, 0);
            for(int r = l; r < col; r++) {
                for(int i = 0; i < row; i++) {
                    sums[i] += A[i][r];
                }
                int sum = 0;
                set<int> st;
                st.insert(0);
                for(int i = 0; i < row; i++) {
                    sum += sums[i];
                    auto it = st.lower_bound(sum - k);
                    if(it != st.end()) {
                        ret = max(ret, sum - *it);
                    }
                    st.insert(sum);
                }
            }
        }
        return ret;
    }
};
