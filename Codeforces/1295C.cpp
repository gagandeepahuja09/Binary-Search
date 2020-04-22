#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
     
int main() {
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i++) {
            pos[s[i] - 'a'].push_back(i);
        }
        int currPos = 0, ans = 0;
        bool flag = true;
        // else {
            for(int i = 0; i < t.size(); i++) {
                auto& v = pos[t[i] - 'a'];
                auto it = lower_bound(v.begin(), v.end(), currPos);
                if(it == v.end()) {
                    it = lower_bound(v.begin(), v.end(), 0);
                    if(it == v.end()) {
                        ans = -2;
                        break;
                    }
                    ans++;
                }
                currPos = (*it) + 1;
            }
            if(!flag) {
                cout << -1 << '\n';
            }
            else
                cout << ans + 1 << '\n';
        // }
    }
}
