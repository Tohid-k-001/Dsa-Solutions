class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        string t = "1" + s + "1";

        vector<char> ch;
        vector<int> len;

        int n = t.size();
        int i = 0;

        while (i < n) {
            int j = i;
            while (j < n && t[j] == t[i])
                j++;

            ch.push_back(t[i]);
            len.push_back(j - i);

            i = j;
        }

        int gain = 0;

        for (int i = 1; i + 1 < ch.size(); i++) {
            if (ch[i] == '1' && ch[i - 1] == '0' && ch[i + 1] == '0') {
                gain = max(gain, len[i - 1] + len[i + 1]);
            }
        }

        return ones + gain;
    }
};