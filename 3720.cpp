class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        int freq[26] = {};

        for (char c : s) {
            freq[c - 'a']++;
        }

        string prefix = "";

        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Case 1: We can keep the same character
            if (freq[x] > 0) {
                freq[x]--;
                prefix += target[i];
                continue;
            }

            // Case 2: We cannot keep target[i].
            // Try making the current position bigger.
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = prefix;
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

            // Can't make current position bigger.
            // We need to backtrack.
            while (!prefix.empty()) {

                int j = prefix.size() - 1;

                // Put the previous character back
                freq[prefix[j] - 'a']++;

                prefix.pop_back();

                int prev = target[j] - 'a';

                // Find smallest character > target[j]
                for (int c = prev + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        string ans = prefix;
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

        // target itself was possible.
        // We still need something greater.
        while (!prefix.empty()) {

            int j = prefix.size() - 1;

            freq[prefix[j] - 'a']++;
            prefix.pop_back();

            int x = target[j] - 'a';

            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string ans = prefix;
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