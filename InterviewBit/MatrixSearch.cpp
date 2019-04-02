int binarySearch(vector<vector<int>>& A, int i, int jLow, int jHigh, 
int x) {
    while(jLow <= jHigh) {
        int jMid = (jLow + jHigh) / 2;
        if(A[i][jMid] == x) {
            return 1;
            // cout << i << " " << j << endl;
        }
        else if(x < A[i][jMid]) {
            jHigh = jMid - 1;
        }
        else {
            jLow = jMid + 1;
        }
    }
    return 0;
}

int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    int n = A.size(), m = A[0].size();
    if(n == 1) {
        return binarySearch(A, 0, 0, m - 1, B);
    }
    // Do binary search on middle column 
    // Condition to terminate => 2 Rows remaining
    int iLow = 0, iHigh = n-1, jMid = m/2;
    while((iLow + 1) < iHigh) {
        int iMid = (iLow + iHigh) / 2;
        if(A[iMid][jMid] == B) {
            return 1;
        }
        else if(B < A[iMid][jMid]) {
            iHigh = iMid;
        }
        else {
            iLow = iMid;
        }
    }
    if(A[iLow][jMid] == B)
        return 1;
    if(A[iLow + 1][jMid] == B)
        return 1;    
    // 1st half of 1st row
    if(B <= A[iLow][jMid - 1])    
        return binarySearch(A, iLow, 0, jMid - 1, B);
    // 2nd half of 1st row    
    else if(B >= A[iLow][jMid + 1] && B <= A[iLow][m - 1])
        return binarySearch(A, iLow, jMid + 1, m - 1, B);
        
    // 2nd half of 1st row
    else if(B <= A[iLow + 1][jMid - 1])    
        return binarySearch(A, iLow + 1, 0, jMid - 1, B);
    // 2nd half of 2nd row    
    else if(B >= A[iLow + 1][jMid + 1] && B <= A[iLow + 1][m - 1])
        return binarySearch(A, iLow + 1, jMid + 1, m - 1, B);    
    return 0;    
}

