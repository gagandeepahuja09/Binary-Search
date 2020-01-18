class RangeModule {
public:
    set<pair<int, int>> st;
    RangeModule() {
        st.clear();
    }
    
    void addRange(int left, int right) {
        auto it = st.upper_bound({ left, right });
        // Move one step forward if no intersection
        if(it != st.begin() && (--it) -> second < left) {
            it++;
        }
        while(it != st.end() && it -> first <= right) {
            left = min(left, it -> first);
            right = max(right, it -> second);
            it = st.erase(it);
        }
        st.insert({ left, right });
    }
    
    bool queryRange(int left, int right) {
        auto it = st.upper_bound({ left, INT_MAX });
        return (it != st.begin() && right <= (--it) -> second);
    }
    
    void removeRange(int left, int right) {
        // Move one step back if intersection
        auto it = st.upper_bound({ left, right });
        if(it != st.begin() && left >= (--it) -> second)
            ++it;
        while(it != st.end() && it -> first < right) {
            if(it -> first < left) {
                st.insert({ it -> first, left });
            }
            if(it -> second > right) {
                st.insert({ right, it -> second });
            }
            it = st.erase(it);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
