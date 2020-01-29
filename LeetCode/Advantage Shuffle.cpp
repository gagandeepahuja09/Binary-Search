class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> ret;
        multiset<int> st;
        for(int i = 0; i < A.size(); i++) {
            st.insert(A[i]);
        }
        for(int i  = 0; i < B.size(); i++) {
            auto it = st.upper_bound(B[i]);
            if(it != st.end()) {
                ret.push_back(*it);
                st.erase(it);
            }
            else {
                ret.push_back(*(st.begin()));
                st.erase(st.begin());
            }
        }
        return ret;
    }
};
