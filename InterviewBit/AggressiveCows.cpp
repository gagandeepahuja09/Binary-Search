/*
Farmer John has built a new long barn, with N stalls. Given an array of integers A of size N where each element of the array represents the location of the stall, and an integer B which represent the number of cows.

His cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, John wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
*/

bool isPossible(int dist, vector<int>& A, int cows) {
    cows--;
    int placed = A[0];
    for(int i = 0; i < A.size(); i++) {
        if(A[i] - placed >= dist) {
            cows--;
            placed = A[i];
        }
    }
    return (cows <= 0);
}

int Solution::solve(vector<int> &A, int cows) {
    sort(A.begin(), A.end());
    int l = INT_MAX, h = A.back();
    for(int i = 0; i < A.size() - 1; i++)
        l = min(l, A[i + 1] - A[i]);
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(isPossible(mid, A, cows) && !isPossible(mid + 1, A, cows))
            return mid;
        else if(!isPossible(mid, A, cows))
            h = mid - 1;
        else
            l = mid + 1;
    }
    return h;
}

