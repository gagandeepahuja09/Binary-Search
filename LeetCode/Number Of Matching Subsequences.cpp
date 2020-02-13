class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ret = 0;
        vector<vector<int>> cnt(26);
        for(int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a'].push_back(i);
        }
        
        for(string curr : words) {
            int pos = 0, i = 0, flag = true;
            for(; i < curr.size(); i++) {
                int idx = curr[i] - 'a';
                auto it = lower_bound(cnt[idx].begin(), cnt[idx].end(), pos);
                if(it == cnt[idx].end()) {
                    flag = false;
                    break;
                }
                pos = (*it) + 1;
            }
            ret += flag;
        }
        return ret;
    }
};
