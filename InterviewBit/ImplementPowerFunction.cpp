int Solution::pow(int x, int n, int d) {
    if(x == 0)
        return 0;
    if(n == 0)
        return 1;
    bool negative = false;
    if(x < 0) {
        x = abs(x);
        if(n & 1)
            negative = true;
    }
    long rem = 1, temp = x%d;
    
    while(n != 0) {
        if(n & 1) {
            rem = (rem * temp) % d;
        }
        temp = temp * temp;
        temp = temp % d;
        
        n /= 2;
        if(rem > d)
            rem %= d;
    }
    if(negative) {
        return  (d - (int)rem);
    }
    return (int)rem;
}

