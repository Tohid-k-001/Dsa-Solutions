class Solution {
public:
    const long long LIMIT = 1000000;

    vector<long long> fact;

    long long countWays(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt)
            total += x;

        long double ans = 1;

        vector<int> rem = cnt;

        for (int i = 2; i <= total; i++) {
            ans *= i;

            for (int j = 0; j < 26; j++) {
                while (rem[j] > 1 && ans >= rem[j]) {
                    ans /= rem[j];
                    rem[j]--;
                }
            }

            if (ans > LIMIT)
                return LIMIT;
        }

        for (int j = 0; j < 26; j++) {
            while (rem[j] > 1) {
                ans /= rem[j];
                rem[j]--;
            }
        }

        return min((long long)ans, LIMIT);
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);

        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] % 2)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        string left = "";

        int len = 0;
        for (int x : half)
            len += x;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long ways = countWays(half);

                if (ways >= k) {
                    left.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};