class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> pref(m, -1);

        int p = 0;

        for (int i = 0; i < m; i++) {
            while (p < n && word1[p] != word2[i]) {
                p++;
            }

            if (p == n)
                break;

            pref[i] = p;
            p++;
        }
        vector<int> suff(m, -1);

        p = n - 1;

        for (int i = m - 1; i >= 0; i--) {
            while (p >= 0 && word1[p] != word2[i]) {
                p--;
            }

            if (p < 0)
                break;

            suff[i] = p;
            p--;
        }

        vector<int> runEnd(n);

        runEnd[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (word1[i] == word1[i + 1])
                runEnd[i] = runEnd[i + 1];
            else
                runEnd[i] = i;
        }


        int bestPos = -1;
        int bestMismatch = -1;

        int lastPossiblePos = -1;
        int lastPossibleMismatch = -1;

        for (int i = 0; i < m; i++) {

            int previous = (i == 0 ? -1 : pref[i - 1]);

            if (i > 0 && previous == -1)
                break;

            int start = previous + 1;

            if (start >= n)
                continue;

            int mismatch;

            if (word1[start] != word2[i]) {
                mismatch = start;
            } 
            else {
                mismatch = runEnd[start] + 1;
            }

            if (mismatch >= n)
                continue;

            if (word1[mismatch] == word2[i])
                continue;

            if (i < m - 1) {
                if (suff[i + 1] == -1)
                    continue;

                if (mismatch >= suff[i + 1])
                    continue;
            }
            lastPossiblePos = i;
            lastPossibleMismatch = mismatch;

            if (pref[i] == -1 || mismatch < pref[i]) {

                bestPos = i;
                bestMismatch = mismatch;

                break;
            }
        }

        if (bestPos == -1) {
            if (pref[m - 1] != -1) {
                return pref;
            }

            if (lastPossiblePos == -1) {
                return {};
            }

            bestPos = lastPossiblePos;
            bestMismatch = lastPossibleMismatch;
        }


        vector<int> ans;

        for (int i = 0; i < bestPos; i++) {
            ans.push_back(pref[i]);
        }
        ans.push_back(bestMismatch);

        int j = bestMismatch + 1;

        for (int i = bestPos + 1; i < m; i++) {

            while (j < n && word1[j] != word2[i]) {
                j++;
            }

            ans.push_back(j);
            j++;
        }

        return ans;
    }
};
