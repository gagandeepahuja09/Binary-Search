#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), left, right;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int k, x, pos = -1;
        cin >> k >> x;
        // Use binary search to optimize time
        for(int i = 0; i < n; i++) {
            if(a[i] == x)
                pos = i;
        }
        int l = pos - 1, r = pos + 1;
        while((l >= 0 || r < n) && k) {
            if(l >= 0) {
                if(k) {
                    k--;
                    left.push_back(a[l--]);
                }
            }
            if(r < n) {
                if(k) {
                    k--;
                    right.push_back(a[r++]); 
                }
            }
        }
        reverse(left.begin(), left.end());
        for(int i = 0; i < left.size(); i++)
            cout << left[i] << " ";
        for(int i = 0; i < right.size(); i++)
            cout << right[i] << " ";    
        cout << endl;
    }
	return 0;
}
