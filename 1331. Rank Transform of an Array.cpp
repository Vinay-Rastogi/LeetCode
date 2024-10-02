#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {

        if (arr.size() == 0)
            return arr;

        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> mp;
        int rank = 0;

        for (int i = 0; i < copy.size() - 1; i++)
        {
            if (copy[i] != copy[i + 1])
            {
                rank++;
            }
            mp[copy[i]] = rank;
        }

        mp[copy[copy.size() - 1]] = rank + 1;
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};

int main()
{
    Solution sl;
    vector<int> arr = {40, 10, 20, 30};
    vector<int> ans = sl.arrayRankTransform(arr);

    return 0;
}