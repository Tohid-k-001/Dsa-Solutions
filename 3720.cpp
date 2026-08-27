class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {};

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = target;

        // Try to keep matching target from left to right
        for (int i = 0; i < target.size(); i++) {

            // Can we use target[i]?
            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
                continue;
            }

            // We cannot match target[i].
            // Go backwards to find a position to increase.
            for (int j = i; j >= 0; j--) {

                // Put back the character used at j
                freq[target[j] - 'a']++;

                // Find the smallest character > target[j]
                for (int c = target[j] - 'a' + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        ans = target.substr(0, j);

                        ans += char('a' + c);
                        freq[c]--;

                        // Put remaining characters in sorted order
                        for (int k = 0; k < 26; k++) {
                            while (freq[k] > 0) {
                                ans += char('a' + k);
                                freq[k]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // target itself can be formed.
        // But we need STRICTLY greater.
        // So try to increase from the last position.
        for (int j = target.size() - 1; j >= 0; j--) {

            freq[target[j] - 'a']++;

            for (int c = target[j] - 'a' + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    ans = target.substr(0, j);
                    ans += char('a' + c);
                    freq[c]--;

                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};