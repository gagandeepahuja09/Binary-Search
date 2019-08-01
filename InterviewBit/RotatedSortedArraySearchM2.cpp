int findPivot(const vector<int> &A) {
    int l = 0, h = A.size() - 1;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(m < A.size() - 1 && A[m] > A[m + 1])
            return m;
        if(m > 0 && A[m] < A[m - 1])
            return m - 1;
        if(A[l] > A[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return l;
}

int bSearch(const vector<int>& A, int l, int h, int target) {
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(A[m] == target)
            return m;
        if(A[m] < target)
            l = m + 1;
        else
            h = m - 1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int pivot = findPivot(A);
    int l = bSearch(A, 0, pivot, B);
    if(l != -1)
        return l;
    return bSearch(A, pivot + 1, A.size() - 1, B);    
}

