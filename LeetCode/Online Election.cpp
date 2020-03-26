class TopVotedCandidate {
public:
    int lowerBound(vector<vector<int>>& timeLeader, int t) {
        int low = 0, high = timeLeader.size() - 1, ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            // the first element of the vector is time and we want
            // to do binary search on time
            if(timeLeader[mid][0] <= t) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        // the second element of the vector is the person and we need to output the number 
        return timeLeader[ans][1];
    }
    
    vector<vector<int>> timeLeader;
    TopVotedCandidate(vector<int>& p, vector<int>& t) {
        int leader = -1;
        vector<int> count(5001, 0);
        for(int i = 0; i < p.size(); i++) {
            count[p[i]]++;
            if(leader == -1 || count[p[i]] >= count[leader]) {
                leader = p[i];
            }
            timeLeader.push_back({ t[i], leader });
        }
    }
    
    int q(int t) {
        // return 0;
        return lowerBound(timeLeader, t); 
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
