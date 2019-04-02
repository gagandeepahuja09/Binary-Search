int Solution::sqrt(int A) {
    if(A == 0 || A == 1)
        return A;
    int low = 1, high = A, ans;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid == A / mid) {
            return mid;
        }
        else if(mid < A / mid) {
            // Since we need floor, so we update answer when mid * mid 
            // < A and move closer to A
            low = mid + 1;
            ans = mid;
        }
        else 
            high = mid - 1;
    }
    return ans;
}

