class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int i = 0; i < 9; i++) {

            for (int j = 0; j < 9; j++) {

                char ch = board[i][j];

                // Ignore empty cells
                if (ch == '.') {
                    continue;
                }

                // Find which 3x3 box this cell belongs to
                int box = (i / 3) * 3 + (j / 3);

                // Check if number already exists
                if (rows[i].find(ch) != rows[i].end()) {
                    return false;
                }

                if (cols[j].find(ch) != cols[j].end()) {
                    return false;
                }

                if (boxes[box].find(ch) != boxes[box].end()) {
                    return false;
                }

                // Insert the number
                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[box].insert(ch);
            }
        }

        return true;
    }
};