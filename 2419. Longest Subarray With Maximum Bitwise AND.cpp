#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {

        int ans = 0;
        int len = 0;
        int maxE = *max_element(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == maxE)
                len++;

            else
                len = 0;

            ans = max(len, ans);
        }

        return ans;
    }
};

int main()
{
    Solution sl;
    vector<int> nums = {1, 2, 3, 3, 2, 2};

    cout << sl.longestSubarray(nums);

    return 0;
}