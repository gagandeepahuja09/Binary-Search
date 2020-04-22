#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int

bool isSub(int mid, vector<int> v, string t, string p) {
    for(int i = 0; i <= mid; i++) {
        t[v[i] - 1] = '0';
    }
    int j = 0;
    for(int i = 0; i < t.size(); i++) {
        if(t[i] == '0') continue;
        if(t[i] == p[j])    j++;
    }
    return (j >= p.size());
}
     
int main() {
    // int T;
    // cin >> T;
    // while(T--) {
        string t, p;
        cin >> t >> p;
        vector<int> v;
        for(int i = 0; i < t.size(); i++) {
            int n;
            cin >> n;
            v.push_back(n);
        }
        int low = 0, high = t.size() - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isSub(mid, v, t, p)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        cout << ans + 1 << endl;
    // }
}
