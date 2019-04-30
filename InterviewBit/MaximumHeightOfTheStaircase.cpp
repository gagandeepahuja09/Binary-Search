/*Given an integer A representing the square blocks. The height of each square block is 1. The task is to create a staircase of max height using these blocks.

The first stair would require only one block, the second stair would require two blocks and so on.

Find and return the maximum height of the staircase.*/


#define ll long long int

int Solution::solve(int A) {
    ll l = 1, h = A;
    while(l <= h) {
        ll mid = l + (h - l) / 2;
        ll maxStair = (mid * (mid + 1)) / 2;
        ll higher = ((mid + 1) * (mid + 2)) / 2;
        if(maxStair <= A && higher > A) {
            return (int)mid;
        }
        else if(maxStair > A) {
            h = mid - 1;
        }
        else if(maxStair < A)
            l = mid + 1;
    }
}

