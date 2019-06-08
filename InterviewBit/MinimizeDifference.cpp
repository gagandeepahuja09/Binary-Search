/*

Minimum Difference

You are given a 2D matrix of size N×M. You need to build a new 1D array of size N by taking
one element from each row of the 2D matrix. But the newly build array should have the 
minimum possible value of the absolute difference between any two adjacent elements.

So if the newly built array is A[], element picked from row 1 will become A[1], 
element picked from row 2 will become A[2], and so on.

Determine the minimum possible value of the absolute difference between any two adjacent 
elements in the newly build array.

*/

int closest(int k, vector<int>& v) {
    int l = 0, h = v.size() - 1;
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(v[m] == k || (m < v.size() - 1 && v[m] <= k && v[m + 1] >= k)) {
            return min(abs(v[m] - k), abs(v[m + 1] - k));
        }
        if(m > 0 && v[m - 1] <= k && v[m] >= k)
            return min(abs(v[m] - k), abs(v[m - 1] - k));
        if(v[m] < k)
            l = m + 1;
        else
            h = m - 1;
    }
    return min(abs(v[l] - k), abs(v[h] - k));
}

int Solution::solve(int A, int B, vector<vector<int> > &C) {
    for(int i = 0; i < C.size(); i++) {
        sort(C[i].begin(), C[i].end());
    }
    int mn = INT_MAX;
    for(int i = 0; i < C.size() - 1; i++) {
        for(int j = 0; j < C[0].size(); j++) {
            mn = min(mn, closest(C[i][j], C[i + 1]));
        }
    }
    return mn;
}

