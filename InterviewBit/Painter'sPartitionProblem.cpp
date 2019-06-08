#define ll long long int
#define MOD 10000003

bool isPossible(vector<int>& A, ll paint, int k) {
    ll sum = 0;
    for(int i = 0; i < A.size(); i++) {
        sum += A[i];
        if(sum > paint) {
            k--;
            sum = A[i];
        }
    }
    if(sum > paint)
        k--;
    return k > 0;
}

int Solution::paint(int A, int B, vector<int> &C) {
    ll l = INT_MIN, h = 0;
    for(int i = 0; i < C.size(); i++) {
        l = max(l, (ll)C[i]);
        h += C[i];
    }
    while(l <= h) {
        ll mid = l + (h - l) / 2;
        if(isPossible(C, mid, A) && !isPossible(C, mid - 1, A)) {
            ll ans = (B % MOD *  mid % MOD) % MOD;
            return (int)ans;
        }
        else if(!isPossible(C, mid, A))
            l = mid + 1;
        else
            h = mid - 1;
    }
    ll ans = (B % MOD *  l % MOD) % MOD;
    return (int)ans;
}

