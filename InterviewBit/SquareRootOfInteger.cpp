int Solution::sqrt(int A) {
    if(A == 0 || A == 1)
        return A;
    int l = 1, h = A, ans;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(m == A / m)
            return m;
        else if(m < A / m) {
            ans = m;
            l = m + 1;
        }
        else
            h = m - 1;
    }
    return ans;
}
