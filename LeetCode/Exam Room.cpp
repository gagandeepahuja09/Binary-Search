struct IntV {
    static int N;
    int l, r;
    IntV(int l, int r) : l(l), r(r) {}
    
    int getDist() const {
        if(l == 0)  return r;
        if(r == N - 1)  return (N - 1 - l);
        return (r - l) / 2;
    }
    
    int getMid() const {
        if(l == 0)  return 0;
        if(r == N - 1)  return N - 1;
        return l + (r - l) / 2;
    }
    
    bool operator < (const IntV &a) const {
        int d1 = getDist(), d2 = a.getDist();
        return (d1 == d2) ? l < a.l : d1 > d2;
    }
};

int IntV :: N = 0;

class ExamRoom {
public:
    set<IntV> tab;
    unordered_map<int, int> l2r, r2l;
    
    ExamRoom(int N) {
        IntV :: N = N;
        tab.clear(); l2r.clear(); r2l.clear();
        tab.insert(IntV(0, N - 1));                                                                       l2r[0] = N - 1;
        r2l[N - 1] = 0;
    }
    
    int seat() {
        IntV curr = *(tab.begin());
        tab.erase(tab.begin());
        
        int mid = curr.getMid();
        tab.insert(IntV(curr.l, mid - 1));
        tab.insert(IntV(mid + 1, curr.r));
        l2r[curr.l] = mid - 1;   r2l[mid - 1]  = curr.l;
        l2r[mid + 1] = curr.r,   r2l[curr.r] = mid + 1;
        return mid;
    }
    
    void leave(int p) {
        int l = r2l[p - 1], r = l2r[p + 1];
        tab.erase(IntV(l, p - 1));
        tab.erase(IntV(p + 1, r));
        tab.insert(IntV(l, r));
        l2r[l] = r; 
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
