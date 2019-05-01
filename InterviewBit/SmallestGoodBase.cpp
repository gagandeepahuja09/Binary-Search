#define ll long long int
/*
Given an integer A, we call k >= 2 a good base of A, if all digits of A base k are 1.
Now given a string representing A, you should return the smallest good base of A in 
string format.
*/

ll isPossible(ll k, ll x) {
    ll sum = 0, m = 1;
    for(int i = 0; i < x; i++) {
        sum += m;
        m *= k;
    }
    // cout << "(" << sum << " " << k << " )";
    return sum;
}

string Solution::solve(string A) {
    ll l, h;
    ll n = stoll(A);
    // cout << n << endl;
    for(int i = 63; i >= 1; i--) {
        l = 2, h = n - 1;
        while(l <= h) {
            ll mid = l + (h - l) / 2;
            // cout << mid << " ";
            if(isPossible(mid, i) == n && isPossible(mid + 1, i) > n)
                return to_string(mid);
            else if(isPossible(mid, i) > n)
                h = mid - 1;
            else if(isPossible(mid, i) <= n)
                l = mid + 1;
        }
    }
    return to_string(h);
}

