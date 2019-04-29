/*

Given a sorted array of integers A where every element appears twice except for one element which appears once, find and return this single element that appears only once.

*/

int Solution::solve(vector<int> &A) {
    int l = 0, n = A.size(), h = n - 1;
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if((mid == 0 && A[mid] != A[mid + 1]) 
        || (mid == n - 1 && A[mid] != A[mid - 1]) || 
        (A[mid] != A[mid - 1] && A[mid] != A[mid + 1]))
            return A[mid];
        else if(mid != 0 && A[mid] == A[mid - 1]) {
            if(mid % 2 == 0)
                h = mid - 1;
            else
                l = mid + 1;
        }
        else if(mid != n - 1 && A[mid] == A[mid + 1]) {
            if(mid % 2 == 0)
                l = mid + 1;
            else
                h = mid - 1;
        }
    }
}

