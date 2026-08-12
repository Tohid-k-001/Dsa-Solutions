class Solution {
public:

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {

        int left = 0;
        int count = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            if (isVowel(s[right])) {
                count++;
            }

            if (right - left + 1 > k) {

                if (isVowel(s[left])) {
                    count--;
                }

                left++;
            }

            if (right - left + 1 == k) {
                ans = max(ans, count);
            }
        }

        return ans;
    }
};