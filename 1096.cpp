class Solution {
public:

    set<string> merge(set<string> a, set<string> b) {
        for (auto &x : b) {
            a.insert(x);
        }
        return a;
    }

    set<string> product(set<string> a, set<string> b) {
        set<string> ans;

        for (auto &x : a) {
            for (auto &y : b) {
                ans.insert(x + y);
            }
        }

        return ans;
    }

    set<string> dfs(string &expression, int &i) {

        set<string> result;
        set<string> current;

        current.insert("");

        while (i < expression.size() && expression[i] != '}') {

            if (expression[i] == ',') {

                result = merge(result, current);
                current.clear();
                current.insert("");

                i++;
            }

            else if (expression[i] == '{') {

                i++;

                set<string> inside = dfs(expression, i);

                i++;

                current = product(current, inside);
            }

            else {

                string temp = "";

                while (i < expression.size() &&
                       expression[i] >= 'a' &&
                       expression[i] <= 'z') {

                    temp += expression[i];
                    i++;
                }

                set<string> single;
                single.insert(temp);

                current = product(current, single);
            }
        }

        result = merge(result, current);

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = dfs(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};