class Solution {
public:
    vector<int> pre;
    Solution(vector<int>& w) {
        for(int i : w) {
            pre.push_back(pre.empty() ? i : i + pre.back());
        }
    }
    
    int pickIndex() {
        int rnum = rand() % pre.back() + 1;
        return lower_bound(pre.begin(), pre.end(), rnum) - pre.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
