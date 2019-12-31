class Solution {
public:
    int countLessOrEq(vector<int>& A, int m, int cnt = 0) {
        for(int i = 0; i < A.size(); i++)   cnt += (A[i] <=m);
        return cnt;
    }
    
    int findDuplicate(vector<int>& A) {
        int n = A.size();
        int l = 1, h = n;
        while(l < h) {
            int m = l + (h - l) / 2;
            if(countLessOrEq(A, m) > m) {
                h = m;
            }
            else {
                l = m + 1;
            }
        }
        return l;
    }
};
