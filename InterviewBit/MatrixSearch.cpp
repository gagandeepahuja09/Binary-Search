bool bSearch(vector<vector<int>>& A, int r, int k) {
    int l = 0, h = A[r].size() - 1;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(A[r][m] == k) 
            return 1;
        if(A[r][m] < k)
            l = m + 1;    
        else 
            h = m - 1;
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int r = A.size(), c = A[0].size();
    int l = 0, h = r - 1;
    while(l <= h) {
        if(l == h) {
            return bSearch(A, l, B);
        }
        int m = l  + (h - l) / 2;
        if(A[m][0] <= B && A[m][c - 1] >= B) {
            return bSearch(A, m, B);
        }
        else if(A[m][0] > B) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return 0;
}

