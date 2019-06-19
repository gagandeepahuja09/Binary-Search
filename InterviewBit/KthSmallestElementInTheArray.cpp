int Solution::kthsmallest(const vector<int> &A, int B) {
    int l = INT_MAX, h = INT_MIN;
    for(int i = 0; i < A.size(); i++) {
        l = min(l, A[i]);
        h = max(h, A[i]);
    }
    while(l <= h) {
        int m = l + (h - l) / 2;
        int c0 = 0, c1 = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < m)
                c0++;
            if(A[i] == m)
                c1++;
        }
        if(c0 < B && c0 + c1 >= B)
            return m;
        else if(c0 >= B)
            h = m - 1;
        else
            l = m + 1;
    }
    return h;
}

