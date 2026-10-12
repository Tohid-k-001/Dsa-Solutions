
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int need = 0;

        for (char c : s) {
            if (c == '(') {
                // If need is odd, insert one ')' to complete
                // the previous pair before starting a new '('
                if (need % 2 == 1) {
                    ans++;
                    need--;
                }

                // Each '(' requires two ')'
                need += 2;
            }
            else {
                need--;

                // Too many closing parentheses
                if (need < 0) {
                    ans++;
                    need = 1;
                }
            }
        }

        // Insert missing closing parentheses
        return ans + need;
    }
};
