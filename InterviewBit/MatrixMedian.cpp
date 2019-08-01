int Solution::findMedian(vector<vector<int> > &A) {
    int l = INT_MAX, h = INT_MIN, m = A.size(), n = A[0].size();
    for(int i = 0; i < m; i++) {
        l = min(l, A[i][0]);
        h = max(h, A[i][n - 1]);
    }
    while(l < h) {
        int mid = l + (h - l) / 2, cnt = 0;
        for(int i = 0; i < m; i++) {
            cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        }
        if(cnt < ((m * n + 1)/ 2))
            l = mid + 1;
        else
            h = mid;
    }
    return l;
}

