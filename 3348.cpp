#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int,int>> factor = {
        {0, {}},
        {1, {}},
        {2, {{2,1}}},
        {3, {{3,1}}},
        {4, {{2,2}}},
        {5, {{5,1}}},
        {6, {{2,1},{3,1}}},
        {7, {{7,1}}},
        {8, {{2,3}}},
        {9, {{3,2}}}
    };

    string smallestNumber(string num, long long t) {
        auto [need, ok] = getPrimeCount(t);
        if (!ok) return "-1";

        auto cnt = compress(need);

        if (sum(cnt) > (int)num.size())
            return build(cnt);

        auto prefix = getPrimeCount(num);

        int firstZero = num.find('0');
        if (firstZero == string::npos) {
            firstZero = num.size();
            if (subset(need, prefix))
                return num;
        }

        for (int i = (int)num.size()-1; i>=0; i--) {
            int d = num[i]-'0';

            prefix = subtract(prefix, factor[d]);

            int rem = num.size()-1-i;

            if (i > firstZero) continue;

            for (int nd=d+1; nd<=9; nd++) {

                auto req = compress(
                    subtract(
                        subtract(need,prefix),
                        factor[nd]
                    )
                );

                if (sum(req) <= rem) {

                    int ones = rem-sum(req);

                    return num.substr(0,i)
                         + char('0'+nd)
                         + string(ones,'1')
                         + build(req);
                }
            }
        }

        auto req = compress(need);

        return string(num.size()+1-sum(req),'1') + build(req);
    }

private:

    pair<unordered_map<int,int>,bool> getPrimeCount(long long t){
        unordered_map<int,int> c={{2,0},{3,0},{5,0},{7,0}};

        for(int p:{2,3,5,7}){
            while(t%p==0){
                t/=p;
                c[p]++;
            }
        }
        return {c,t==1};
    }

    unordered_map<int,int> getPrimeCount(const string &s){
        unordered_map<int,int> c={{2,0},{3,0},{5,0},{7,0}};

        for(char ch:s){
            for(auto &[p,f]:factor[ch-'0'])
                c[p]+=f;
        }
        return c;
    }

    unordered_map<int,int> subtract(unordered_map<int,int> a,
                                    const unordered_map<int,int> &b){
        for(auto &[k,v]:b)
            a[k]=max(0,a[k]-v);
        return a;
    }

    bool subset(const unordered_map<int,int>&a,
                const unordered_map<int,int>&b){
        for(auto &[k,v]:a)
            if(b.at(k)<v) return false;
        return true;
    }

    int sum(const unordered_map<int,int>&m){
        int s=0;
        for(auto &[_,v]:m) s+=v;
        return s;
    }

    unordered_map<int,int> compress(const unordered_map<int,int>&cnt){

        int c8=cnt.at(2)/3;
        int rem2=cnt.at(2)%3;

        int c9=cnt.at(3)/2;
        int c3=cnt.at(3)%2;

        int c4=rem2/2;
        int c2=rem2%2;

        int c6=0;

        if(c2&&c3){
            c2=0;
            c3=0;
            c6=1;
        }

        if(c3&&c4){
            c2=1;
            c6=1;
            c3=0;
            c4=0;
        }

        return {
            {2,c2},
            {3,c3},
            {4,c4},
            {5,cnt.at(5)},
            {6,c6},
            {7,cnt.at(7)},
            {8,c8},
            {9,c9}
        };
    }

    string build(const unordered_map<int,int>&m){
        string ans;

        for(int d=2; d<=9; d++)
            ans += string(m.at(d), char('0'+d));

        return ans;
    }
};