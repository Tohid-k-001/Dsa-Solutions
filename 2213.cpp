class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int len;
        int prefix;
        int suffix;
        int best;

        Node() {
            leftChar = '#';
            rightChar = '#';

            len = 0;
            prefix = 0;
            suffix = 0;
            best = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0)
            return b;

        if (b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        res.best = max(a.best, b.best);

        // Boundary characters are same
        if (a.rightChar == b.leftChar) {

            // Repeating substring crosses the boundary
            res.best = max(res.best,
                           a.suffix + b.prefix);

            // Entire left segment has same character
            if (a.prefix == a.len) {
                res.prefix = a.len + b.prefix;
            }

            // Entire right segment has same character
            if (b.suffix == b.len) {
                res.suffix = b.len + a.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {

            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        tree[node] = merge(tree[2 * node],
                            tree[2 * node + 1]);
    }

    void update(int node, int l, int r,
                int index, char ch) {

        if (l == r) {

            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (index <= mid) {
            update(2 * node, l, mid, index, ch);
        }
        else {
            update(2 * node + 1, mid + 1, r, index, ch);
        }

        tree[node] = merge(tree[2 * node],
                            tree[2 * node + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices) {

        int n = s.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, index, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};