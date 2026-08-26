class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            
            // We only start when we find a '1'
            if (s[i] != '1')
                continue;

            int count = 0;

            for (int j = i; j < n; j++) {
                
                if (s[j] == '1')
                    count++;

                // We found exactly k ones
                if (count == k) {
                    
                    string curr = s.substr(i, j - i + 1);

                    // First valid answer
                    if (ans == "") {
                        ans = curr;
                    }
                    // Shorter answer
                    else if (curr.length() < ans.length()) {
                        ans = curr;
                    }
                    // Same length but lexicographically smaller
                    else if (curr.length() == ans.length() && curr < ans) {
                        ans = curr;
                    }

                    break;
                }
            }
        }

        return ans;
    }
};