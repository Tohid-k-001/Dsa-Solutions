class Solution {
public:

    struct Node {
        int l, r, w, idx;
    };

    struct State {
        long long score = 0;
        array<int, 4> ids = {-1, -1, -1, -1};
        int cnt = 0;
    };

    vector<Node> a;
    vector<vector<State>> dp;
    vector<vector<bool>> vis;

    State solve(int i, int k) {

        if (i >= a.size() || k == 0) {
            return State();
        }

        if (vis[i][k]) {
            return dp[i][k];
        }

        vis[i][k] = true;

        // -------------------------
        // 1. SKIP current interval
        // -------------------------
        State skip = solve(i + 1, k);


        // -------------------------
        // 2. TAKE current interval
        // -------------------------

        // Find first interval with start > current end
        int lo = i + 1;
        int hi = a.size();

        while (lo < hi) {

            int mid = lo + (hi - lo) / 2;

            if (a[mid].l > a[i].r) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }

        int next = lo;

        State nxt = solve(next, k - 1);

        State take;

        take.score = a[i].w + nxt.score;

        // nxt can have at most k-1 elements.
        // Since k <= 4, take can have at most 4.
        take.cnt = nxt.cnt + 1;

        take.ids = nxt.ids;

        // Insert current index into sorted order
        int pos = 0;

        while (pos < nxt.cnt &&
               take.ids[pos] < a[i].idx) {
            pos++;
        }

        // Shift elements to the right
        for (int j = take.cnt - 1; j > pos; j--) {
            take.ids[j] = take.ids[j - 1];
        }

        take.ids[pos] = a[i].idx;


        // -------------------------
        // Compare TAKE and SKIP
        // -------------------------

        if (take.score > skip.score) {
            return dp[i][k] = take;
        }

        if (take.score < skip.score) {
            return dp[i][k] = skip;
        }

        // Same score.
        // Choose lexicographically smaller indices.

        int limit = min(take.cnt, skip.cnt);

        for (int j = 0; j < limit; j++) {

            if (take.ids[j] < skip.ids[j]) {
                return dp[i][k] = take;
            }

            if (take.ids[j] > skip.ids[j]) {
                return dp[i][k] = skip;
            }
        }

        // If one is a prefix of the other,
        // smaller number of elements is lexicographically smaller.
        if (take.cnt < skip.cnt) {
            return dp[i][k] = take;
        }

        return dp[i][k] = skip;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        a.reserve(n);

        for (int i = 0; i < n; i++) {

            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end(), [](const Node& x, const Node& y) {

            if (x.l != y.l)
                return x.l < y.l;

            if (x.r != y.r)
                return x.r < y.r;

            return x.idx < y.idx;
        });


        dp.resize(n, vector<State>(5));
        vis.resize(n, vector<bool>(5, false));


        State ans = solve(0, 4);

        vector<int> result;

        for (int i = 0; i < ans.cnt; i++) {
            result.push_back(ans.ids[i]);
        }

        return result;
    }
};