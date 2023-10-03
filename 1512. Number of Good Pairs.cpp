#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numIdenticalPairs(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;

        for (auto it : mp)
            if (it.second > 1)
                ans += it.second * (it.second - 1) / 2;

        return ans;
    }
};

int main()
{

    Solution sl;
    vector<int> nums = {1, 2, 3, 1, 1, 3};

    cout << sl.numIdenticalPairs(nums);

    return 0;
}