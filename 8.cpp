class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int sign = 1;
        int ans = 0;

        // Skip spaces
        while (i < s.size() && s[i] == ' ')
            i++;

        // Check sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++;
        }

        // Read digits
        while (i < s.size() && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Overflow check
            if (ans > INT_MAX / 10 ||
                (ans == INT_MAX / 10 && digit > 7)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};