int bSearch(const vector<int>& A, int l, int h, int B) {
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(A[mid] == B)
            return mid;
        else if(A[mid] < B)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int l = 0, n = A.size(), h = n - 1, idx = h;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(mid != n - 1 && A[mid] > A[mid + 1]) {
            idx = mid;
            break;
        }
        else if(A[mid] > A[n - 1]) {
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    if(B >= A[0] && B <= A[idx])
        return bSearch(A, 0, idx, B);
    else
        return bSearch(A, idx + 1, n - 1, B);
}

