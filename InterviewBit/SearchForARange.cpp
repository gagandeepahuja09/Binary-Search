int upperBound(const vector<int>& A, int B, int low, int high) {
    if(low > high) {
        return -1;    
    }
    int mid = low + (high - low)/2;
    if(A[mid] == B && (mid == A.size() - 1 || B < A[mid + 1]))
        return mid;
    else if(A[mid] > B) {
        return upperBound(A, B, low, mid - 1);
    }
    else {
        return upperBound(A, B, mid + 1, high);
    }
}

int lowerBound(const vector<int>& A, int B, int low, int high) {
    if(low > high) {
        return -1;    
    }
    int mid = low + (high - low)/2;
    if(A[mid] == B && (mid == 0 || B > A[mid - 1]))
        return mid;
    else if(A[mid] < B) {
        return lowerBound(A, B, mid + 1, high);
    }
    else {
        return lowerBound(A, B, low, mid - 1);
    }
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    int u = upperBound(A, B, 0, A.size() - 1);
    int l = lowerBound(A, B, 0, A.size() - 1);
    return { l, u };
}

