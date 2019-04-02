

    bool isPossible(vector<int>& A, int M, int currMin) {
        int currSum = 0, studentsReq = 1;
        for(int i=0; i < A.size(); i++) {
            if(A[i] > currMin)
                return false;
            if(currSum + A[i] > currMin) {
                studentsReq++;
                currSum = A[i];
                if(studentsReq > M)
                    return false;
            }
            else 
                currSum += A[i];
        }
        return true;
    }
     
    int Solution::books(vector<int> &A, int M) {
        long sum = 0;
        if(A.size() < M)
            return -1;
        for(int i=0; i < A.size(); i++) {
            sum += A[i];
        }
        int start = 0, end = sum;
        int res = INT_MAX;
        while(start <= end) {
            int mid = (start + end) / 2;
            if(isPossible(A, M, mid)) {
                res = min(res, mid);
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return res;
    }


