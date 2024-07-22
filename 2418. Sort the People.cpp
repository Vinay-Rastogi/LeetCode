#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {

        map<int, string, greater<int>> mp;
        vector<string> res;

        for (int i = 0; i < names.size(); i++)
            mp[heights[i]] = names[i];

        for (auto it : mp)
            res.push_back(it.second);

        return res;
    }
};

int main()
{

    Solution sl;
    vector<string> names = {"Mary", "John", "Emma"};
    vector<int> heights = {180, 165, 170};
    vector<string> res = sl.sortPeople(names, heights);

    return 0;
}