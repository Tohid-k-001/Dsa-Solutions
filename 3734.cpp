class Solution {
public:

    string makePalindrome(string left, char mid) {
        string right = left;
        reverse(right.begin(), right.end());

        return left + string(1, mid) + right;
    }

    bool possible(string left, char mid, vector<int>& cnt, string target) {

        // Put remaining characters in decreasing order
        string remaining = "";

        for (int i = 25; i >= 0; i--) {
            remaining += string(cnt[i], 'a' + i);
        }

        // Largest possible left half
        string newLeft = left + remaining;

        // Build palindrome
        string candidate = makePalindrome(newLeft, mid);

        return candidate > target;
    }

    string lexPalindromicPermutation(string s, string target) {

        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether palindrome is possible
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Characters available for left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        int n = s.length();
        int halfLen = n / 2;

        string left = "";

        for (int pos = 0; pos < halfLen; pos++) {

            // Try smallest character first
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                // Choose this character
                left += char('a' + c);
                half[c]--;

                // Check if some valid completion exists
                if (possible(left, mid, half, target)) {
                    break;
                }

                // This character doesn't work
                left.pop_back();
                half[c]++;
            }
        }

        string answer = makePalindrome(left, mid);

        if (answer > target)
            return answer;

        return "";
    }
};