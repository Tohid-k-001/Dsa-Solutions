class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> pref(m, -1);

        int p = 0;

        for (int j = 0; j < m; j++) {

            while (p < n && word1[p] != word2[j]) {
                p++;
            }

            if (p == n)
                break;

            pref[j] = p;
            p++;
        }
        vector<int> latest(m, -1);

        p = n - 1;

        for (int j = m - 1; j >= 0; j--) {

            while (p >= 0 && word1[p] != word2[j]) {
                p--;
            }

            if (p < 0)
                break;

            latest[j] = p;
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


        vector<int> answer;

        // case 1
        if (pref[m - 1] != -1) {
            answer = pref;
        }

        // case 2
        for (int j = 0; j < m; j++) {

            // Last index used by the exact prefix
            int prev = (j == 0 ? -1 : pref[j - 1]);

            // If prefix cannot be formed, no later j works.
            if (j > 0 && prev == -1)
                break;

            int start = prev + 1;

            if (start >= n)
                continue;


            // Find the earliest index whose character
            // is DIFFERENT from word2[j].
            int mismatchIndex;

            if (word1[start] == word2[j]) {

                // Skip the entire run of this character.
                mismatchIndex = runEnd[start] + 1;

            } else {

                mismatchIndex = start;
            }


            // No position available for mismatch.
            if (mismatchIndex >= n)
                continue;


            // Make sure it really is a mismatch.
            if (word1[mismatchIndex] == word2[j])
                continue;


            // If this isn't the last character,
            // we must still be able to form the suffix exactly.
            if (j != m - 1) {

                if (latest[j + 1] == -1)
                    continue;

                // We need some valid suffix position
                // strictly after mismatchIndex.
                if (mismatchIndex >= latest[j + 1])
                    continue;
            }


            // Build candidate answer.
            vector<int> candidate;

            // Exact prefix
            for (int k = 0; k < j; k++) {
                candidate.push_back(pref[k]);
            }

            // One mismatch
            candidate.push_back(mismatchIndex);


            // Match remaining suffix exactly.
            int q = mismatchIndex + 1;
            bool possible = true;

            for (int k = j + 1; k < m; k++) {

                while (q < n && word1[q] != word2[k]) {
                    q++;
                }

                if (q == n) {
                    possible = false;
                    break;
                }

                candidate.push_back(q);
                q++;
            }


            if (possible) {

                if (answer.empty() || candidate < answer) {
                    answer = candidate;
                }
            }
        }

        return answer;
    }
};
