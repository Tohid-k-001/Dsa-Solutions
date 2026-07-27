class Solution {
public:
    long long sumOfGCD(vector<int>& nums) {

        vector<int> prefixGcd;
        int mx = 0;

        // Build prefixGcd
        for (int x : nums) {
            mx = max(mx, x);
            prefixGcd.push_back(__gcd(x, mx));
        }

        // Sort
        sort(prefixGcd.begin(), prefixGcd.end());

        long long ans = 0;

        int i = 0;
        int j = prefixGcd.size() - 1;

        // Form pairs
        while (i < j) {
            ans += __gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};