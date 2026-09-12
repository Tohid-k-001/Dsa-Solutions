class Solution {
public:

    struct Node {
        int l;
        int r;
        int w;
        int idx;
    };

    vector<Node> a;
    
    // dp[i][k] = best result from i onward,
    // where we can still choose k intervals.
    pair<long long, vector<int>> dp[50001][5];

    bool visited[50001][5] = {};

    pair<long long, vector<int>> solve(int i, int k) {

        if (i == a.size() || k == 0) {
            return {0, {}};
        }

        if (visited[i][k]) {
            return dp[i][k];
        }

        visited[i][k] = true;

        // Option 1: skip current interval
        auto skip = solve(i + 1, k);

        // Option 2: take current interval

        int r = a[i].r;

        // Find first interval whose start > r
        int lo = i + 1;
        int hi = a.size();

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (a[mid].l > r) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        int next = lo;

        auto takeNext = solve(next, k - 1);

        long long takeScore = a[i].w + takeNext.first;

        vector<int> takeIndices = takeNext.second;
        takeIndices.push_back(a[i].idx);

        sort(takeIndices.begin(), takeIndices.end());

        pair<long long, vector<int>> take = {
            takeScore,
            takeIndices
        };

        // Compare
        if (take.first > skip.first) {
            return dp[i][k] = take;
        }

        if (take.first < skip.first) {
            return dp[i][k] = skip;
        }

        // Same score → lexicographically smaller
        if (take.second < skip.second) {
            return dp[i][k] = take;
        }

        return dp[i][k] = skip;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting position
        sort(a.begin(), a.end(), [](Node& x, Node& y) {
            if (x.l != y.l)
                return x.l < y.l;

            return x.r < y.r;
        });

        return solve(0, 4).second;
    }
};