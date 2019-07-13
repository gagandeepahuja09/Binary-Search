#define ll long long int

class Solution {
public:
    vector<int> power;
    int MOD = 1000000007;
    string isPossible(int len, string s) {
        unordered_map<ll, vector<int>> mp;
        ll num = 0;
        for(int i = 0; i < len; i++) {
            num = num + (power[i] * (s[i] - 'a' + 1));
        }
        mp[num] = vector<int>(1, 0);
        for(int i = len; i < s.size(); i++) {
            num = (num -  (s[i- len] - 'a' + 1));
            num = num / 26 + (power[len - 1] * (s[i] - 'a' + 1));
            if(mp.find(num) != mp.end()) {
                for(auto k : mp[num]) {
                    int curr = i - len + 1;
                    string s1 = s.substr(k, len);
                    string s2 = s.substr(curr, len);
                    if(s1 == s2)
                        return s1;
                }
                mp[num].push_back(i - len + 1);
            }
            else
                mp[num] = vector<int>(1, i - len + 1);
        }
        return "";
    }
    
    string longestDupSubstring(string S) {
        power[0] = 1;
        for(int i = 0; i < 100001; i++)
            power.push_back((power.back() * 26) % MOD);
        int l = 0, h = S.size();
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(isPossible(m, S).size() && !isPossible(m + 1, S).size())
                return isPossible(m, S);
            else if(!isPossible(m, S).size())
                h  = m - 1;
            else
                l = m + 1;
        }
        return "";
    }
};
