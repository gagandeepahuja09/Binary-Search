class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        map<int, int> mp;
        for(int i = 0; i < in.size(); i++) {
            mp[in[i][0]] = i;
        }
        vector<int> ret;
        for(int i = 0; i < in.size(); i++) {
            auto it = mp.lower_bound(in[i][1]);
            if(it == mp.end())
                ret.push_back(-1);
            else
                ret.push_back(it -> second);
        }
        return ret;
    }
};
