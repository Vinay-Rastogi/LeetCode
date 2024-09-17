#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> uncommonFromSentences(string s1, string s2)
    {

        string s = s1 + " " + s2;

        unordered_map<string, int> um;
        string tmp = "";
        for (auto &val : s)
        {
            if (val == ' ')
            {
                um[tmp]++;
                tmp = "";
            }
            else
            {
                tmp += val;
            }
        }

        if (tmp != "")
        {
            um[tmp]++;
            tmp = "";
        }

        vector<string> ans;
        for (auto &val : um)
        {

            if (val.second == 1)
            {
                ans.emplace_back(val.first);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sl;

    string s1 = "this apple is sweet";
    string s2 = "this apple is sour";

    vector<string> ans = sl.uncommonFromSentences(s1, s2);

    return 0;
}