class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        vector<int> val(w.size(), 0);
        for(int i = 0; i < w.size(); i++) {
            map<char, int> mp;
            for(int j = 0; j < w[i].size(); j++) {
                mp[w[i][j]]++;
            }
            for(auto it = mp.begin(); it != mp.end(); it++) {
                if(it -> second) {
                    val[i] = it -> second;
                    break;
                }
            }
        }
        sort(val.begin(), val.end());
        vector<int> ret;
        for(int i = 0; i < q.size(); i++) {
            int curr;
            map<char, int> mp;
            for(int j = 0; j < q[i].size(); j++) {
                mp[q[i][j]]++;
            }
            for(auto it = mp.begin(); it != mp.end(); it++) {
                if(it -> second) {
                    curr = it -> second;
                    break;
                }
            }
            int cnt = 0;
            for(int j = 0; j < val.size(); j++) {
                if(val[j] > curr)
                    cnt++;
            }
            ret.push_back((int)val.size() - (int)(upper_bound(val.begin(), val.end(), curr) - val.begin()));
        }
        return ret;
    }
};
