class Solution {
public:
    vector<int> concatenateAndCalculate(string s, vector<vector<int>>& queries) {

        const long long MOD = 1000000007;
        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<long long> prefSum(n + 1, 0);
        vector<long long> hash(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            prefSum[i + 1] = prefSum[i] + (s[i] - '0');
            hash[i + 1] = hash[i];

            if (s[i] != '0') {
                cnt[i + 1]++;
                hash[i + 1] = (hash[i] * 10 + (s[i] - '0')) % MOD;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sum = prefSum[r + 1] - prefSum[l];

            int k = cnt[r + 1] - cnt[l];

            long long x = (hash[r + 1] - (hash[l] * pow10[k]) % MOD + MOD) % MOD;

            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};