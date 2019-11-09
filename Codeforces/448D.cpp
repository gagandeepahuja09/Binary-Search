#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll f(ll mid, ll n, ll m) {
    ll cnt = 0;
    for(ll i = 1; i <= n; i++) {
        cnt += min(m, mid / i);
    }
    return cnt;
}

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1, r = n * m + 1;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        if(f(mid, n, m) < k) {
            l = mid + 1;
        }
        else
            r = mid;
    }
    cout << l << endl;
}
