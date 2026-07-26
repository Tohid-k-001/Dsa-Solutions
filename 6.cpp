class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> rows(numRows);

        int row = 0;
        bool down = true;

        for (char ch : s) {

            rows[row] += ch;

            if (row == numRows - 1)
                down = false;
            else if (row == 0)
                down = true;

            if (down)
                row++;
            else
                row--;
        }

        string ans = "";

        for (string str : rows)
            ans += str;

        return ans;
    }
};