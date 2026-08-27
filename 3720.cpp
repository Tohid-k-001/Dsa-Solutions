class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int freq[26] = {};

        // Count characters of s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Try to match target from left to right
        for (int i = 0; i < n; i++) {

            // If target[i] is available, use it
            if (freq[target[i] - 'a'] > 0) {
                freq[target[i] - 'a']--;
            }
            else {
                // We cannot continue.
                // Go backwards and try to make something bigger.

                for (int j = i - 1; j >= 0; j--) {

                    // Return the character used at position j
                    freq[target[j] - 'a']++;

                    // Find smallest character > target[j]
                    for (int c = target[j] - 'a' + 1; c < 26; c++) {

                        if (freq[c] > 0) {

                            string ans = target.substr(0, j);

                            // Make this position slightly bigger
                            ans += char('a' + c);
                            freq[c]--;

                            // Add remaining characters in sorted order
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
        }

        // target itself can be formed.
        // But we need something STRICTLY greater.
        for (int j = n - 1; j >= 0; j--) {

            // Return the character used at j
            freq[target[j] - 'a']++;

            // Find smallest character greater than target[j]
            for (int c = target[j] - 'a' + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = target.substr(0, j);

                    ans += char('a' + c);
                    freq[c]--;

                    // Smallest possible suffix
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