int bSearch(vector<vector<int>>& A, int r, int l, int h, int target) {
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(A[r][mid] == target)
            return 1;
        else if(A[r][mid] < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int target) {
    int m = A.size(), n = A[0].size() - 1;
    int l = 0, h = A.size() - 1;
    while(h - l > 1) {
        int mid = l + (h - l) / 2;
        if(A[mid][n / 2] == target)
            return 1;
        else if(A[mid][n / 2] < target)
            l = mid;
        else
            h = mid;
    }
    // cout << l << " " << h << endl;
    if(A[l][n / 2] == target || A[h][n / 2] == target)
        return 1;
    if(target >= A[l][0] && target <= A[l][n / 2])
        return bSearch(A, l, 0, n / 2, target);
    else if(target >= A[l][n / 2] && target <= A[l][n])
        return bSearch(A, l, n / 2, n, target);
    else if(target >= A[h][0] && target <= A[h][n / 2])
        return bSearch(A, h, 0, n / 2, target);
    else
        return bSearch(A, h, n / 2, n, target);
}

