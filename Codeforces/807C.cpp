#include <bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define vvi vector<vi>
#define read(a)  for(int i = 0; i < n; i++) cin >> a[i];
#define print(a)  for(int i = 0; i < n; i++) cout << a[i] << " ";
#define pb push_back
#define pql priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define pqlv priority_queue<vi>
#define pqsv priority_queue<vi, vvi, greater<vi>>
#define endl '\n'
#define N 300002
#define MOD 1000000007
 
 bool check(int x, int y, int p, int q, int t) {
     return (x <= p * t && y - x <= (q - p) * t);
 }

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--) {
        int x, y, p, q;
        cin >> x >> y >> p >> q;
        if(!check(x, y, p, q, 1e9)) {
            cout << -1 << endl;
        }
        else {
            int low = 0, high = 1e9, ans = high;
            while(low <= high) {
                int mid = low + (high - low) / 2;
                if(check(x, y, p, q, mid)) {
                    ans = mid;
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            cout << (q * ans - y) << endl;
        }
    }
	return 0;
}
