#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {

        vector<pair<int, int>> v;

        for (int i = 0; i < groupSizes.size(); i++)
            v.push_back({groupSizes[i], i});

        sort(v.begin(), v.end());

        vector<vector<int>> ans;

        for (int i = 0; i < groupSizes.size();)
        {

            int n = v[i].first;
            vector<int> temp;
            int j;

            for (j = i; j < n + i; j++)
                temp.push_back(v[j].second);

            ans.push_back(temp);

            i = j;
        }

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};

    vector<vector<int>> res = sl.groupThePeople(groupSizes);

    return 0;
}