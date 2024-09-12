#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countConsistentStrings(string allowed, vector<string> &words)
    {

        unordered_map<char, int> mp;
        int ans = words.size();

        for (char ch : allowed)
            mp[ch]++;

        for (string s : words)
        {
            for (char c : s)
            {
                if (mp.find(c) == mp.end())
                {

                    ans--;
                    break;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sl;

    string allowed = "ab";
    vector<string> words = {"ad", "bd", "aaab", "baa", "badab"};

    cout << sl.countConsistentStrings(allowed, words);

    return 0;
}