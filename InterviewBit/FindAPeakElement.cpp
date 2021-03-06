/* Given an array of integers A, find and return the peak element in it. An array element is peak if it is NOT smaller than its neighbors. For corner elements, we need to consider only one neighbor. For example, for input array {5, 10, 20, 15}, 20 is the only peak element. */

int Solution::solve(vector<int> &A) {
    int l = 0, h = A.size() - 1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if((mid == A.size() - 1 && A[mid] > A[mid - 1]) || (mid == 0 && A[mid] > A[mid + 1])
            || (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]))
            return A[mid];
        if(A[mid] < A[mid + 1])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return A[l];
}


