/*Consider a 3-tuple of integers (A,B,C) under the constraints that A<=B and C<=B.

A function on the tuple is defined as:

F(A,B,C)=0 if A>B or C>B (or both).
F(A,B,C)=(A+B)*(B+C) if A<=B and C<=B.

Given 3 arrays of size P,Q,R respectively.

Find the sum of all F(A,B,C) over all the 3-tuples (A,B,C) where A,B,C belong to the arrays P,Q,R respectively.
*/

#define MOD 1000000007
#define ll long long int

int Solution::getSum(int A, int B, int C, vector<int> &D, vector<int> &E, vector<int> &F) {
    sort(D.begin(), D.end());
    sort(F.begin(), F.end());
    vector<int> pD(D.size(), 0), pF(F.size(), 0);
    pD[0] = D[0];
    for(int i = 1; i < D.size(); i++) {
        pD[i] = D[i] + pD[i - 1];
    }
    pF[0] = F[0];
    for(int i = 1; i < F.size(); i++) {
        pF[i] = F[i] + pF[i - 1];
    }
    ll ans = 0;
    for(int i = 0; i < E.size(); i++) {
        int curr = E[i];
        int n = upper_bound(D.begin(), D.end(), curr) - D.begin();
        int m = upper_bound(F.begin(), F.end(), curr) - F.begin();
        ans = ans % MOD + ((pD[n - 1] % MOD + n % MOD * E[i] % MOD) % MOD
        * (pF[m - 1] % MOD + m % MOD * E[i] % MOD) % MOD) % MOD;
    }
    return (int)ans;
}

