int lowerBound(const vector<int>& A, int target) {
    int l = 0, h = A.size() - 1;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(A[m] == target && (m == 0 || A[m] > A[m - 1])) {
            return m;
        }
        else if(A[m] < target) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    return -1;
}

int upperBound(const vector<int>& A, int target) {
    int l = 0, h = A.size() - 1;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(A[m] == target && (m == A.size() - 1 || A[m] < A[m + 1])) {
            return m;
        }
        else if(A[m] > target) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int l = lowerBound(A, B);
    int r = upperBound(A, B);
    return { l, r };
}

