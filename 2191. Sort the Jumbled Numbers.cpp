#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
    {
        if (p1.first < p2.first)
        {
            return true;
        }
        else if (p1.first == p2.first)
        {
            return p1.second < p2.second;
        }
        return false;
    }
    vector<int> sortJumbled(vector<int> &mp, vector<int> &nums)
    {

        vector<pair<int, int>> v;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {

            string s = to_string(nums[i]);

            for (int j = 0; j < s.length(); j++)
                s[j] = mp[s[j] - '0'] + '0';

            int n = stoi(s);
            v.push_back({n, i});
        }

        sort(v.begin(), v.end(), cmp);

        for (int i = 0; i < v.size(); i++)
            ans.push_back(nums[v[i].second]);

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> mapping = {8, 9, 4, 0, 2, 1, 3, 5, 7, 6};
    vector<int> nums = {991, 338, 38};

    vector<int> ans = sl.sortJumbled(mapping, nums);

    return 0;
}