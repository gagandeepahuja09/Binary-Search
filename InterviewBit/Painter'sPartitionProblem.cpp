#define ll long long int
#define MOD 10000003

bool isPossible(vector<int>& v, ll paint, int k) {
    int cnt = 0;
    ll currPaint = 0;
    for(int i = 0; i < v.size(); i++) {
        currPaint += v[i];
        if(currPaint > paint) {
            cnt++;
            currPaint = v[i];
        }
    }
    if(currPaint > paint)
        cnt++;
    return (cnt < k);
}

int Solution::paint(int A, int B, vector<int> &C) {
    ll l = INT_MIN, h = 0;
    for(int i = 0; i < C.size(); i++) {
        l = max(l, (ll)C[i]);
        h += C[i];
    }
    while(l <= h) {
        ll m = l + (h - l) / 2;
        if(isPossible(C, m, A)) {
            h = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    return (int)((l % MOD * B % MOD) % MOD);
}

