class Solution {
public:
    int countSmaller(vector<int>& A, int val) {
        int cnt = 0;
        for(int j = 1; j < A.size(); j++) {
            int l = 0, h = j - 1;
            while(l < h) {
                int m = (h + l + 1) / 2;
                if(A[m] / A[j] < val) {
                    l = m;
                }
                else {
                    h = m - 1;
                }
            }
            if(l == h) {
                cnt += ((A[l] / A[j] < val) ? l + 1 : l);
            }
        }
        return cnt;
    }
    
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        unordered_set<int> st;
        for(int i : A)
            st.insert(i);
        double l = 1.0 / 30000.0, h = 29999.0 / 30000.0;
        double err = pow(10, -9);
        while(h - l > err) {
            double m = (h + l) / 2.0;
            if(countSmaller(A, m) < K - 1) {
                l = m;    
            }
            else {
                h = m;
            }
        }
        cout << l << endl;
        for(int i = 0; i < A.size(); i++) {
            int numerator = (int)round(A[i] * l);
            if(numerator < A[i] && st.count(numerator) && abs(numerator / A[i] - l) < err) {
                return { numerator, A[i] };
            }
        }
        return {};
    }
};
