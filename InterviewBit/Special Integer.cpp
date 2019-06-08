#define ll long long int

bool possible(vector<ll>& A, int sum, int k) {
    ll mx = A[k - 1];
    for(int i = k; i < A.size(); i++)
        mx = max(mx, A[i] - A[i - k]);
    return (mx <= sum);    
}

int Solution::solve(vector<int> &A, int B) {
    int l = 1, h = A.size();
    vector<ll> sum(h, 0);
    sum[0] = A[0];
    for(int i = 1; i < A.size(); i++)
        sum[i] = A[i] + sum[i - 1];
    while(l <= h) {
        int m = l + (h - l) / 2;
        if(possible(sum, B, m) && !possible(sum, B, m + 1))
            return m;
        if(possible(sum, B, m))
            l = m + 1;
        else
            h = m - 1;
    }
    return h;
}

