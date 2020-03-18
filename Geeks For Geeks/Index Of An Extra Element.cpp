int findExtra(int a[], int b[], int n) {
    int low = 0, high = n - 1, ans = n - 1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(mid != n - 1 && a[mid] == b[mid]) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
