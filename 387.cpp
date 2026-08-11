#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        unordered_map<char,int>mp;
        // count frequencies of each character
        for(char ch: s){
            mp[ch]++;
        }

        for(int i=0;i<s.size();i++){
            if(mp[s[i]]==1){
                return i;
            }
        }

        return -1;
        
    }
};