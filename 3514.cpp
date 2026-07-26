class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        vector<bool> present(2048, false);

        for (int x : nums)
            present[x] = true;

        vector<int> values;
        for (int i = 0; i < 2048; i++)
            if (present[i])
                values.push_back(i);

        vector<vector<bool>> dp(4, vector<bool>(2048, false));

        dp[0][0] = true;

        for (int taken = 0; taken < 3; taken++) {
            for (int xr = 0; xr < 2048; xr++) {

                if (!dp[taken][xr]) continue;

                for (int val : values) {
                    dp[taken + 1][xr ^ val] = true;
                }
            }
        }

        int ans = 0;

        for (bool x : dp[3])
            if (x) ans++;

        return ans;
    }
};