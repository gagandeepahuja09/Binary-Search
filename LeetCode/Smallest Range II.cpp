class TopVotedCandidate {
public:
    vector<int> times;
    unordered_map<int, int> mp;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this -> times = times;
        unordered_map<int, int> cnt;
        int winner = 0;
        for(int i = 0; i < persons.size(); i++) {
            if(++cnt[persons[i]] >= cnt[winner])
                winner = persons[i];
            mp[times[i]] = winner;
        }
    }
    
    int q(int t) {
        return mp[*--upper_bound(times.begin(), times.end(), t)];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
