#define ull unsigned long long 

class Solution {
public:
    ull binarySearch(ull num, ull power) {
        double tn = (double)num;
        ull low = 2, high = (unsigned long long)(pow(tn,1.0/power)+1);         
        while(low <= high) {
            // mid here is a possible base
            ull mid = low + (high - low) / 2;
            ull sum = 0, val = 1;
            for(int i = 0; i <= power; i++) {
                sum += val;
                val *= mid;
            }
            if(sum == num)
                return mid;
            else if(sum > num) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
    
    string smallestGoodBase(string n) {
        ull num = stoll(n);
        for(ull i = 62; i >= 1; i--) {
            ull ans = binarySearch(num, i);
            if(ans != -1)
                return to_string(ans);
        }
        return to_string(num - 1);
    }
};
