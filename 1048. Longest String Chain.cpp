#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(const string &s1, const string &s2)
    {

        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &words)
    {

        sort(words.begin(), words.end(), cmp);

        int ans = 0;
        unordered_map<string, int> mp;

        for (string s : words)
        {

            int longest = 0;

            for (int i = 0; i < s.length(); i++)
            {
                string sub = s;
                sub.erase(i, 1);
                longest = max(longest, mp[sub] + 1);
            }

            mp[s] = longest;
            ans = max(ans, longest);
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};

    cout << sl.longestStrChain(words);

    return 0;
}