/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    int findPeak(MountainArray &mount) {
        int l = 0, h = mount.length() - 1, n = h;
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(m == 0)
                m = 1;
            int n1 = 0, n2 = 0, n3 = 0;
            if(mp.find(m) == mp.end()) {
                mp[m] = mount.get(m);
            }
            n1 = mp[m];
            if(mp.find(m - 1) == mp.end()) {
                mp[m - 1] = mount.get(m - 1);
            }
            n2 = mp[m - 1];
            if(mp.find(m + 1) == mp.end()) {
                mp[m + 1] = mount.get(m + 1);
            }
            n3 = mp[m + 1];
            if((m < n && n3 < n1) && (m > 0 && n2 < n1))
                return m;
            if(m < n && n3 < n1)
                h = m - 1;
            else
                l = m + 1;
        }
        return -1;
    }
    
    int bSearch(bool flag, MountainArray &mount, int k, int l, int h) {
        while(l <= h) {
            int m = l + (h - l) / 2;
            if(mp.find(m) == mp.end())
                mp[m] = mount.get(m);
            int n1 = mp[m];
            if(n1 == k)
                return m;
            if(flag == 0) {
                if(n1 < k)
                    l = m + 1;
                else
                    h = m - 1;
            }
            else {
                if(n1 > k)
                    l = m + 1;
                else
                    h = m - 1;
            }
        }
        return -1;
    }
    
    int findInMountainArray(int k, MountainArray &mount) {
        mp.clear();
        int peak = findPeak(mount);
        if(peak == -1)
            return peak;
        if(bSearch(0, mount, k, 0, peak) != -1)
                return bSearch(0, mount, k, 0, peak);
        return bSearch(1, mount, k, peak + 1, mount.length() - 1);
    }
};
