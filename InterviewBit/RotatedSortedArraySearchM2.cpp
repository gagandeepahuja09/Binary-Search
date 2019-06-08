int rotationIndex(const vector<int>& A) {
    int l = 0, h = A.size() - 1;
    while(l < h) {
        int mid = l + (h - l) / 2;
        if(mid + 1 < A.size() && A[mid] > A[mid + 1])
            return mid;
        if(mid > 0 && A[mid] < A[mid - 1])
            return mid - 1;
        if(A[l] >= A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return h;
}

int bSearch(const vector<int>& A, int l, int h, int k) {
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(A[mid] == k) {
            return mid;
        }
        if(A[mid] > k)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    int pivot = rotationIndex(A);
    int l = 0;
    int index = bSearch(A, l, pivot, B);
    if(index != -1)
        return index;
    return bSearch(A, pivot + 1, A.size() - 1, B);    
}

