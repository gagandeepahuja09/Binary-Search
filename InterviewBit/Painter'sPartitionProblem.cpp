bool isPossible(vector<int>& A, int paint, long currMin) {
    long currSum = 0, count = 1;
    for(int i=0; i < A.size(); i++) {
        if(A[i] > currMin)
            return false;
    }
    for(int i = 0; i < A.size(); ) {
        if(currSum + (long)(A[i]) > currMin) {
            count++;
            currSum;
        }
        else {
            currSum = currSum + (long)(A[i]);
            i++;
        }
    }
    if(count <= paint)
        return true;
    return false;    
}

int Solution::paint(int K, int T, vector<int> &A) {
    long low = 0, high = 0;
    for(int i=0; i<A.size(); i++) {
        high += A[i];
    }
    long res = INT_MAX;
    while(low <= high) {
        long mid = (low + high) / 2;
        if(isPossible(A, K, mid)) {
            res = min(res, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return (int)((res * (long)T) % 10000003);
}

