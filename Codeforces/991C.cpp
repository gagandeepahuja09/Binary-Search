#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define ins insert
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'

bool isPossible(int n, int k) {
    int temp = n, sum = 0;
    while(n) {
        int curr = min(n, k);
        n -= curr;
        sum += curr;
        n -= (n / 10);
    }
    return (2 * sum >= temp);
}

signed main() {
    int t = 1;
    // cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int low = 1, high = n, ans = n;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossible(n, mid)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
	return 0;
}
