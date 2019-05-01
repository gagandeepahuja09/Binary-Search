#define ll long long int

bool isPossible(int pages, vector<int>& A, int students) {
    ll sum = 0;
    for(int i = 0; i < A.size(); i++) {
        if(A[i] > pages)
            return false;
        sum += A[i];
        if(sum > pages) {
            students--;
            sum = A[i];
        }
    }
    if(sum > pages)
        students--;
    return students > 0;
}

int Solution::books(vector<int> &A, int B) {
    ll l = 1, h = 0;
    if(B > A.size())
        return -1;
    for(int i = 0; i < A.size(); i++)
        h += A[i];
    while(l <= h) {
        int mid = l + (h - l) / 2;
        if(isPossible(mid, A, B) && !isPossible(mid - 1, A, B))
            return mid;
        else if(!isPossible(mid, A, B))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return isPossible(h, A, B) ? h : -1;
}

