#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    long long ans = 0;
    sort(c.begin(), c.end());
    for(int i = 0; i < n; i++) {
        if(c[i] <= 0)
            continue;
        int j = lower_bound(c.begin(), c.end(), -c[i] + 1) - c.begin();
        ans += (long long)(i - j);
    }
    cout << ans;
}
