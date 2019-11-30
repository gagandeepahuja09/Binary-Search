/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int f(Sea sea, int x1, int y1, int x2, int y2) {
        if(x2 < x1 || y2 < y1)
            return 0;
        if(!sea.hasShips({ x2, y2 }, { x1, y1 }))
            return 0;
        if(x2 == x1 && y2 == y1 && sea.hasShips({ x1, y1 }, { x2, y2 }))
            return 1;
        int a = (x2 - x1) / 2, b = (y2 - y1) / 2;
        return f(sea, x1, y1, x1 + a, y1 + b) + f(sea, x1 + a + 1, y1 + b + 1, x2, y2)
            + f(sea, x1 + a + 1, y1, x2, y1 + b) + f(sea, x1, y1 + b + 1, x1 + a, y2);
    }
    int countShips(Sea sea, vector<int> t, vector<int> b) {
        int x1 = b[0], y1 = b[1], x2 = t[0], y2 = t[1];
        return f(sea, x1, y1, x2, y2);
    }
};
