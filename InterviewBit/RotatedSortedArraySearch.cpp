int binarySearch(const vector<int>& A, int l, int h, int key) {
    if(l > h)
        return -1;
    int mid = l + (h-l)/2;
    if(A[mid] == key)
        return mid;
    // A[l..mid] is sorted
    if(A[l] <= A[mid]) {
        // We can easily check if key lies in 1st half
        if(key <= A[mid] && key >= A[l])
            return binarySearch(A, l, mid - 1, key);
        return binarySearch(A, mid + 1, h, key);
    }
    // A[l..mid] is not sorted hence, A[mid..h] must be sorted
    if(key <= A[h] && key >= A[mid])
        return binarySearch(A, mid + 1, h, key);
    return binarySearch(A, l, mid - 1, key);
}

int Solution::search(const vector<int> &A, int B) {
    binarySearch(A, 0, A.size() - 1, B);
}

