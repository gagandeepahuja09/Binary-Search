class Solution {
public:
    int smallestDistancePair(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int l = 0, h = 1000001;
        while(l < h) {
            int m = (l + h) / 2, cnt = 0;
            for(int i = 0, j = 0; i < A.size(); i++) {
                while(j < A.size() && A[j] - A[i] <= m) {
                    j++;
                }
                cnt += (j - i - 1);
            }
            if(cnt < k)
                l = m + 1;
            else
                h = m;
        }
        return l;
    }
};
