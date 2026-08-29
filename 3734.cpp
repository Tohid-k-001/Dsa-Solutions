class Solution {
public:

    string build(string left, char mid, bool hasMid) {

        string right = left;
        reverse(right.begin(), right.end());

        if (hasMid)
            return left + string(1, mid) + right;

        return left + right;
    }


    bool canMake(string left, char mid, bool hasMid,
                 vector<int>& cnt, string target) {

        string remaining = "";

        // Make the LARGEST possible remaining half
        for (int i = 25; i >= 0; i--) {
            remaining += string(cnt[i], char('a' + i));
        }

        string candidate = build(left + remaining, mid, hasMid);

        return candidate > target;
    }


    string lexPalindromicPermutation(string s, string target) {

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check if palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {

            if (cnt[i] % 2 == 1) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        bool hasMid = (s.length() % 2 == 1);

        // Frequency for left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        string left = "";

        // Build left half
        for (int pos = 0; pos < s.length() / 2; pos++) {

            bool found = false;

            // Try smallest character first
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                left.push_back(char('a' + c));
                half[c]--;

                // Can we still make a palindrome > target?
                if (canMake(left, mid, hasMid, half, target)) {

                    found = true;
                    break;
                }

                // Undo
                left.pop_back();
                half[c]++;
            }

            // Nothing worked
            if (!found)
                return "";
        }

        string answer = build(left, mid, hasMid);

        if (answer > target)
            return answer;

        return "";
    }
};