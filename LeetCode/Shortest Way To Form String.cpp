/*

From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.

Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".

 

Constraints:

    Both the source and target strings consist of only lowercase English letters from "a"-"z".
    The lengths of source and target string are between 1 and 1000.

*/

class Solution {
public:
    int shortestWay(string s, string t) {
        unordered_map<char, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            mp[s[i]].push_back(i);    
        }
        if(!t.size())
            return 0;
        int cnt = 0, pos = -1;
        for(int i = 0; i < t.size(); i++) {
            if(!mp[t[i]].size())
                return -1;
            auto it = upper_bound(mp[t[i]].begin(), mp[t[i]].end(), pos);
            if(it == mp[t[i]].end()) {
                pos = *(mp[t[i]].begin());
                cnt++;
            }
            else {
                pos = *it;
            }
        }
        return cnt + 1;
    }
};
