int Solution::searchInsert(vector<int> &A, int B) {
    int l = 0, h = A.size();
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(A[m] == B || ((m == 0 || A[m - 1] < B) && (m  == A.size() || A[m] > B)))
            return m;
        else if(A[m] < B)
            l = m + 1;
        else
            h = m - 1;
    }
    return h;
}
