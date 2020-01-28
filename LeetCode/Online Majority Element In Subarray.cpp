class MajorityChecker {
public:
    unordered_map<int, vector<int>> idx;
    vector<int> A;
    MajorityChecker(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            idx[arr[i]].push_back(i);
        }
        A = arr;
    }
    
    int query(int left, int right, int threshold) {
        for(int n = 0; n < 20; n++) {
            int num = A[left + rand() % (right - left + 1)]      ;
            auto it1 = lower_bound(idx[num].begin(), idx[num].end(), left);
            auto it2 = upper_bound(idx[num].begin(), idx[num].end(), right);    
            if(it2 - it1 >= threshold)
                return num;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
