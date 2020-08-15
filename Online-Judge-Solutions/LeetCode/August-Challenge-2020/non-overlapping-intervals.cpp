class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if ((int)intervals.size() == 0) return 0;
        vector <pair <int, int> > v;
        for (vector <int> i : intervals) {
            v.emplace_back(i[0], i[1]);
        }

        sort(v.begin(), v.end(), [](const pair <int, int> &a, const pair <int, int> &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        int n = (int)v.size();
        int nonOverlapping = 1;
        int lastTaken = v[0].second;
        for (int i = 1; i < n; ++i) {
            if (lastTaken <= v[i].first) {
                lastTaken = v[i].second;
                ++nonOverlapping;
            }
        }
        return n - nonOverlapping;
    }
};
