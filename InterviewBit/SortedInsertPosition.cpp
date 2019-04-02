int Solution::searchInsert(vector<int> &A, int target) {
    int low = 0, high = A.size() - 1;
    if(target < A[low])
        return low;
    if(target > A[high])
        return high + 1;
    // Return the index of least element >= target
    // Lower Bound
    while(low < high) {
        int mid = (low + high)/2;
        if(A[mid] < target)
            low = mid + 1;
        else if(A[mid] > target)
            high = mid;
        else
            return mid;
    }
    return low;
}
