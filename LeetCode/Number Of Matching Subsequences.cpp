class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<vector<int>> alpha(26);
        for(int i = 0; i < S.size(); i++) {
            alpha[S[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(auto word : words) {
            bool found = true;
            int x = -1;
            for(char c : word) {
                auto it = upper_bound(alpha[c - 'a'].begin(), alpha[c - 'a'].end(), x);
                if(it == alpha[c - 'a'].end())
                    found = false;
                else
                    x = *it;
            }
            if(found)
                ans++;
        }
        return ans;
    }
};
