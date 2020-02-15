class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& ins) {
        map<int, int> hash;
        int n = ins.size();
        vector<int> ret(n, -1);
        for(int i = 0; i < ins.size(); i++) {
            hash[ins[i][0]] = i;
        }
        for(int i = 0; i < ins.size(); i++) {
            auto minLeft = hash.lower_bound(ins[i][1]);
            if(minLeft != hash.end())
                ret[i] = minLeft -> second;
        }
        return ret;
    }
};
