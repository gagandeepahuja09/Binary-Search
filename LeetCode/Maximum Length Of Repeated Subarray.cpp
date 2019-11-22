class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        const int P = 19941229; //Rabin-Karp
        
        vector<int> hash1(A.size() + 1, 0), hash2(B.size() + 1, 0), p(max(A.size(), B.size()) + 1);
        int len = max(A.size(), B.size());
        p[0] = 1;
        for (int i = 1; i <= len; i++)
            p[i] = p[i - 1] * P;
        for (int i = 1; i <= A.size(); i++)
            hash1[i] = hash1[i - 1] + A[i - 1] * p[i];
        for (int i = 1; i <= B.size(); i++)
            hash2[i] = hash2[i - 1] + B[i - 1] * p[i];
        int l = 1, r = min(A.size(), B.size());
        while (l <= r) { //Binary search the answer
            int m = (l + r) / 2;
            unordered_set<int> hash;
            bool ok = false;
            for (int i = 1; i + m - 1 <= A.size(); i++) //Calculate Rabin-Karp hash for all substring s for the first string of length m, insert into hash table
                hash.insert((hash1[i + m - 1] - hash1[i - 1]) * p[len - (i + m - 1)]);
            for (int i = 1; i + m - 1 <= B.size(); i++){ //Calculate Rabin-Karp hash for the second string, query the hash table
                if (hash.count((hash2[i + m - 1] - hash2[i - 1]) * p[len - (i + m - 1)])) {
                    ok = true;
                    break;
                }
            }
            if (ok)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};
