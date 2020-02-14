class Solution {
public:
    bool canSplit(vector<int>& A, long target, long req) {
        long sum = 0, partitions = 0;
        for(int i = 0; i < A.size(); i++) {
            sum += (long)A[i];
            if(sum > target) {
                partitions++;
                sum = A[i];
            }
        }
        return (partitions < req);
    }
    
    int splitArray(vector<int>& A, int m) {
        long low = (long)*max_element(A.begin(), A.end());
        long high = (long)accumulate(A.begin(), A.end(), 0), ans = high;
        while(low <= high) {
            long mid = low + (high - low) / 2;
            //       cout << mid << endl;
            if(canSplit(A, mid, m)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return (int)ans;
    }
};
