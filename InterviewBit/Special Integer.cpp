/*Given an array of integers A and an integer B, find and return the maximum value K such 
that there is no subarray in A of size K with sum of elements greater than B.
*/

#define ll long long int

ll maxSub(ll k, vector<ll>& A) {
    ll mx = A[k - 1];
    for(int i = k; i < A.size(); i++) {
        mx = max(mx, A[i] - A[i - k]);
    }
    return mx;
}

int Solution::solve(vector<int> &A, int B) {
    int l = 1, h = A.size();
    vector<ll> sum(A.size());
    sum[0] = A[0];
    for(int i = 1; i < A.size(); i++) {
        sum[i] = A[i] + sum[i - 1];
    }
    while(l <= h) {
        ll mid = l + (h - l) / 2;
        if(maxSub(mid, sum) <= B && maxSub(mid + 1, sum) > B) {
            return (int)mid;
        }
        else if(maxSub(mid, sum) >= B)
            h = mid - 1;
        else if(maxSub(mid, sum) < B)
            l = mid + 1;
    }
    return h;
}

