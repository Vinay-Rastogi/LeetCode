#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countHomogenous(string s)
    {

        int MOD = 1e9 + 7;
        map<char, int> mp;
        int ans = 0;

        mp[s[0]]++;
        ans += 1;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] != s[i - 1])
            {
                mp.erase(s[i - 1]);
                mp[s[i]]++;
                ans += 1;
            }
            else
            {
                mp[s[i]]++;
                ans += mp[s[i]];
                ans = ans % MOD;
            }
        }
        return ans;
    }
};

int main()
{

    Solution sl;
    string s = "abbcccaa";

    cout << sl.countHomogenous(s);

    return 0;
}