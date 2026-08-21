class Solution {
public:

    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;
    }

    bool check(long long x, vector<int>& coins, long long k) {

        long long count = 0;

        int n = coins.size();

        // Generate all non-empty subsets
        for (int mask = 1; mask < (1 << n); mask++) {

            long long LCM = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    LCM = lcm(LCM, coins[i]);

                    if (LCM > x)
                        break;
                }
            }

            // Number of multiples of LCM <= x
            long long ways = x / LCM;

            // Inclusion-Exclusion
            if (bits % 2 == 1)
                count += ways;
            else
                count -= ways;
        }

        return count >= k;
    }

    long long findKthSmallest(vector<int>& coins, int k) {

        long long left = 1;
        long long right = 1e11;

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (check(mid, coins, k)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        return left;
    }
};