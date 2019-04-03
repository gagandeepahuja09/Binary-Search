int Solution::findMedian(vector<vector<int>> &A) {
    int low = INT_MIN, high = INT_MAX;
    int r = A.size(), c = A[0].size();
    for(int i=0; i<r; i++) {
        if(A[i][0] < low)
            low = A[i][0];
        if(A[i][c - 1] > high)
            high = A[i][c - 1];
    }
    int desired = (r * c + 1) / 2;
    while(low < high) {
        int mid = low + (high - low) / 2;
        int place = 0;
        // Finding count of all elements greater than mid
        for(int i=0; i < r; i++) {
            place += upper_bound(A[i].begin(), A[i].end(), mid) -
            A[i].begin();
        }
        if(place < desired)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

