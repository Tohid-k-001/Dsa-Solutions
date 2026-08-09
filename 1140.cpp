class Solution {
public:

    int dp[101][101];
    vector<int> suffix;
    int n;

    int solve(int i, int M) {

        // Can take all remaining piles
        if (i + 2 * M >= n)
            return suffix[i];

        if (dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        // Try taking X piles
        for (int X = 1; X <= 2 * M; X++) {

            int nextM = max(M, X);

            int opponent = solve(i + X, nextM);

            int current = suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suffix.resize(n + 1, 0);

        // Calculate suffix sums
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};
