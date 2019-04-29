int countSmaller(vector<vector<int>>& A, int r, int target) {
    int l = 0, h = A[r].size() - 1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(A[r][mid] < target)
            l = mid + 1;
        else if(A[r][mid] > target)
            h = mid - 1;
        else if(mid != 0 && A[r][mid] == A[r][mid - 1])
            h = mid - 1;
        else {
            return mid;
        }
    }
    return l;
}

int countGreater(vector<vector<int>>& A, int r, int target) {
    int l = 0, h = A[r].size() - 1, n = A[r].size();
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(A[r][mid] < target)
            l = mid + 1;
        else if(A[r][mid] > target)
            h = mid - 1;
        else if(mid != n - 1 && A[r][mid] == A[r][mid + 1])
            l = mid + 1;
        else {
            return n - mid - 1;
        }
    }
    return n - l;
}

int Solution::findMedian(vector<vector<int>> &A) {
    int l = INT_MAX, h = INT_MIN, n = A[0].size(), x = A.size() * A[0].size();
    for(int i = 0; i < A.size(); i++) {
        l = min(l, A[i][0]);
    }
    for(int i = 0; i < A.size(); i++) {
        h = max(h, A[i][n - 1]);
    }
    while(l <= h) {
        int sm = 0, gr = 0;
        int mid = l + (h - l) / 2;
        for(int i = 0; i < A.size(); i++) {
            sm += countSmaller(A, i, mid);
            gr += countGreater(A, i, mid);
        }
        // cout << "(" << mid << " " << sm << " " << gr << ")";
        if(sm <= x / 2 && gr <= x / 2)
            return mid;
        else if(gr > x / 2)
            l = mid + 1;
        else
            h = mid - 1;
    }
}

