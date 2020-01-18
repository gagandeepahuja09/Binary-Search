class Solution {
public:
    void horizontal(vector<vector<char>>& A, int i, int j) {
        if(j >= A[0].size() || A[i][j] == '.')
            return;
        A[i][j] = '.';
        horizontal(A, i, j + 1);
    }
    
    void vertical(vector<vector<char>>& A, int i, int j) {
        if(i >= A.size() || A[i][j] == '.')
            return;
        A[i][j] = '.';
        vertical(A, i + 1, j);
    }
    
    int countBattleships(vector<vector<char>>& A) {
        int cnt = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                if(A[i][j] == '.')  continue;
                if(i > 0 && A[i - 1][j] == 'X') continue;
                if(j > 0 && A[i][j - 1] == 'X') continue;
                cnt++;
            }
        }
        return cnt;
    }
};
